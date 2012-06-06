#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);

	ofBackground(255, 255, 255);
	TPR.setup();
	 
	snd.loadSound("drawbar_c4_a.aif");
	snd.setVolume(0);
	snd.setLoop(true);
	snd.play();

    
	
  
}


//--------------------------------------------------------------
void testApp::update(){

    
    if (ofGetMousePressed()){
        
        ofPoint vel = ofPoint(mouseX, mouseY) - prevPos;
        
        // since velocity is a line, we want to know how long it is. 
        float lengthOfVel = ofDist(0,0,vel.x, vel.y);
        
        float soundVolume = ofMap(lengthOfVel, 0,40, 0,1);
        float mixVol = 0.1 * soundVolume + 0.9 * snd.getVolume();
		snd.setVolume(mixVol);
        
        float pitch = ofMap(mouseY, 0, (float)ofGetHeight(), 2.5, 0.1);
        float mixPitch = 0.1 * snd.getSpeed() + 0.9 * pitch;
		snd.setSpeed(mixPitch);
		
    } else {
        
        snd.setVolume(0);
    }

    
     prevPos.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::draw(){

    
	// -------------------------- draw the line
	//TPR.draw();
	
    for (int i = 0; i < strokes.size(); i++){
        
        strokes[i].TPR.draw();
        
        if (strokes[i].TPR.bHaveADrawing()){			// if we have a drawing to work with
            
            // figure out what time we are at, and make sure we playback cyclically (!)
            // use the duration here and make sure our timeToCheck is in the range of 0 - duration
            float timeToCheck = ofGetElapsedTimef() - strokes[i].startTime;
            while (timeToCheck > strokes[i].TPR.getDuration() && strokes[i].TPR.getDuration() > 0){
                timeToCheck -= strokes[i].TPR.getDuration();
            }
            
            // get the position and velocity at timeToCheck
            ofPoint pos = strokes[i].TPR.getPositionForTime(timeToCheck);
            ofPoint vel = strokes[i].TPR.getVelocityForTime(timeToCheck);
            
            // since velocity is a line, we want to know how long it is. 
            float lengthOfVel = ofDist(0,0,vel.x, vel.y);
            
            float soundVolume = ofMap(lengthOfVel, 0,70, 0,1);
            if (ofGetMousePressed()) soundVolume *= 0.05;
            float mixVol = 0.1 * soundVolume + 0.9 * strokes[i].snd.getVolume();
            strokes[i].snd.setVolume(mixVol);
            
            float pitch = ofMap(pos.y, 0, (float)ofGetHeight(), 2.5, 0.1);
            float mixPitch = 0.1 * strokes[i].snd.getSpeed() + 0.9 * pitch;
            strokes[i].snd.setSpeed(mixPitch);
            
            
            ofFill();
            ofSetColor(255,0,0);
            ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
            
            
        }
    }
    
    ofSetColor(0,0,0);
    line.draw();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    for (int i = 0; i < strokes.size(); i++){
        strokes[i].snd.stop();
    }
    
    strokes.clear();
    line.clear();
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}


//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	TPR.addPoint(x,y);
    
    line.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	TPR.startDrawing(x,y);
    line.clear();
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	TPR.endDrawing();
	//playbackStartTime = ofGetElapsedTimef();
    
    sndStroke sndStr;
    sndStr.snd.loadSound("drawbar_c4_a.aif");
	sndStr.snd.setVolume(0);
	sndStr.snd.setLoop(true);
	sndStr.snd.play();
    sndStr.TPR = TPR;
    sndStr.startTime = ofGetElapsedTimef();
    strokes.push_back(sndStr);
    
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}



