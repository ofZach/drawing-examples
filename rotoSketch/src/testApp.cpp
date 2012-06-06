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

    
    float timeT = ofGetElapsedTimef();
    while (timeT > 5) timeT -= 5.0;
    ofDrawBitmapStringHighlight(ofToString(timeT), 30,30);
    
    
    
    ofSetColor(0,0,0);
    
    
    stroke.draw(timeT, 1, 5);
    for (int i = 0; i < strokes.size(); i++){
        strokes[i].draw(timeT, 1, 5);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    strokes.clear();
    stroke.clear();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    float timeT = ofGetElapsedTimef();
    while (timeT > 5) timeT -= 5.0;
    stroke.addVertex(ofPoint(x,y), timeT);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    strokes.push_back(stroke);
    stroke.clear();
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