#include "testApp.h"




//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    
    
    float widthSmooth = 10;
    float angleSmooth;
    
    
    vector < float > transparency;
    vector < ofMesh > meshes;
    for (int i = 0; i < 50; i++){
        ofMesh line;
        line.setMode(OF_PRIMITIVE_LINE_STRIP);
        meshes.push_back(line);
        
        transparency.push_back(  abs(ofSignedNoise(i / 10.0)) );
    }
    
    
    
    ofEnableAlphaBlending();
    
    for (int i = 0;  i < line.getVertices().size(); i++){
        
        
        int me_m_one = i-1;
        int me_p_one = i+1;
        if (me_m_one < 0) me_m_one = 0;
        if (me_p_one ==  line.getVertices().size()) me_p_one =  line.getVertices().size()-1;
        
        ofPoint diff = line.getVertices()[me_p_one] - line.getVertices()[me_m_one];
        float angle = atan2(diff.y, diff.x);
        
        if (i == 0) angleSmooth = angle;
        else {
            
            float diffAngle = angle - angleSmooth;
            while (diffAngle < -PI) diffAngle += TWO_PI ;
            while (diffAngle > PI) diffAngle -= TWO_PI ;
            
            angleSmooth += 0.1f * diffAngle;
            
        }
        
        
        float dist = diff.length();
        
        float w = ofMap(dist, 0, 20, 1, 80, true);
        
        widthSmooth = 0.9f * widthSmooth + 0.1f * w;
        
        ofPoint offset;
        offset.x = cos(angleSmooth + PI/2) * widthSmooth;
        offset.y = sin(angleSmooth + PI/2) * widthSmooth;
        
        ofSetColor(0,0,0);
       // ofLine (line.getVertices()[i] +  offset , line.getVertices()[i] -  offset );
        
        for (int j = 0; j < meshes.size(); j++){
            
            float pctAwayFromCenter = abs(j - meshes.size() / 2.0) / (meshes.size()/2);
            pctAwayFromCenter = powf(pctAwayFromCenter, 3.0);
            float pct = (float) j / (float) meshes.size();
            ofPoint newPt = (pct) * (line.getVertices()[i] +  offset) + (1 - pct) * (line.getVertices()[i] -  offset);
            meshes[j].addColor(ofColor(0,0,0,transparency[j]*200 * (1-pctAwayFromCenter)));
            meshes[j].addVertex(newPt);
            
            //transparency[j] = fabs(ofNoise(j / 10.0f, i / 20.0 + ofGetElapsedTimef()/5.0) - 0.5);
            
            
        }
    }
    
    for (int i = 0; i < meshes.size(); i++){
        meshes[i].draw();
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

    line.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    line.clear();
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