#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofEnableAlphaBlending();
    ofSetColor(30,30,30,30);
    
    for (int i = 0; i < lines.size(); i++){
        
        ofLine( lines[i].a.x, lines[i].a.y, lines[i].b.x, lines[i].b.y);
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

    for (int i = 0; i < drawnPoints.size(); i++){
        ofPoint mouse;
        mouse.set(x,y);
        float dist = (mouse - drawnPoints[i]).length();
        if (dist < 30){
            line lineTemp;
            lineTemp.a = mouse;
            lineTemp.b = drawnPoints[i];
            lines.push_back(lineTemp);
        }
    }
    
    drawnPoints.push_back(ofPoint(x,y));
    
    
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