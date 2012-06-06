#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    //setup of sound input
    // 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	ofSoundStreamSetup(0, 2, this, 44100, 256, 4);	
	left = new float[256];	
	right = new float[256];
    
    #ifdef USE_AUBIO
        AA.setup();
    #endif 
    
    bLoudEnough = false;
    
    total.addVertex(ofPoint(ofGetWidth()/2, ofGetWidth()/2));
}

//--------------------------------------------------------------
void testApp::update(){

    
    bool bLoudEnoughLastFrame = bLoudEnough;
    float pitchSmoothLastFrame = pitchSmooth;
    
    if (volume > 0.01){
        bLoudEnough = true;
    } else {
        bLoudEnough = false;
    }
    
    
    if (bLoudEnough){
        
        // if we were not loud enough last frame, and loud enough this frame, don't smooth: 
        if (!bLoudEnoughLastFrame){
            pitchSmooth = pitch;
        } else {
            pitchSmooth = 0.97f * pitchSmooth + 0.03 * pitch;
            
            
            float diffPitch = pitchSmooth - pitchSmoothLastFrame;
            
            float angleMap = ofMap(diffPitch, -400,400, PI, -PI, true);
            float distance = ofMap(volume, 0.01, 0.04, 0.01, 0.5, true);
            angleDiffs.push_back(angleMap);
            distances.push_back(distance);
        }
        
        
        
        
    }
    
    
    
    
    
    if (angleDiffs.size() > 0){
        
        
        
        angle += angleDiffs[0];
        float dist = distances[0];
        ofPoint lastVertex = total.getVertices()[ total.getVertices().size() - 1 ];
        ofPoint newVeretx = lastVertex + ofPoint( cos(angle) * dist, sin(angle) * dist);
        angleDiffs.erase(angleDiffs.begin());
        total.addVertex(newVeretx.x, newVeretx.y);
        distances.erase(distances.begin());
 
    }
    if (total.getVertices().size() > 0){
        catchPoint = 0.9f * catchPoint + 0.1f * total.getVertices()[total.getVertices().size()-1];
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    
    
    ofDrawBitmapStringHighlight(ofToString(pitchSmooth), ofPoint(50,50), bLoudEnough ? ofColor(255,0,0) : ofColor(0,0,0), ofColor(255,255,255));
    ofDrawBitmapStringHighlight(ofToString(volume), ofPoint(50,80), bLoudEnough ? ofColor(255,0,0) : ofColor(0,0,0), ofColor(255,255,255));
    
    
    ofSetColor(0,0,0);
    if (total.getVertices().size() > 0){
        
        
        ofPushMatrix();
        ofTranslate(-catchPoint.x + ofGetWidth()/2, -catchPoint.y + ofGetHeight()/2);
        
        
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < total.getVertices().size(); i++){
            
            glVertex3f(total.getVertices()[i].x, total.getVertices()[i].y, total.getVertices()[i].z);
        }
        glEnd();
        ofEndShape();
        
        //total.draw();
        ofPopMatrix();
        
        
    }
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void testApp::audioReceived 	(float * input, int bufferSize, int nChannels){	
	
    
#ifdef USE_AUBIO
    
    for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];		
		right[i] = input[i*2+1];
	}
    
    AA.processAudio(left, bufferSize);
    pitch = AA.pitch;
    volume = AA.amplitude;
    
#else 
    
	int zeroCrossings = 0;
	float freq = 0;
	
	//calculate the volume (using Root Mean Square)
	volume = 0; // set the volume to zero
	for(int i=0;i<bufferSize*nChannels;i++){ //go through the entire input array
		volume += input[i]*input[i]; // add the squared value to eliminate any negative values
	}
	volume /= bufferSize*nChannels; // get the average of all the squared values added up
	volume = sqrt(volume); // finally take the square root of that value
	
	if(volume > 0.01){
		for(int i=2;i<bufferSize*nChannels;i+=2){
			if(input[i] > 0 != input[i-2] > 0)
				zeroCrossings++;
		}
	}
	
	freq = (44100.0f/bufferSize) * zeroCrossings/2;
	
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];		
		right[i] = input[i*2+1];
	}
    pitch = freq;
    
    
#endif
    
}
