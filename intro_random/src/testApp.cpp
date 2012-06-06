#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0,0,0);
    
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void testApp::update(){

    
    for (int i = 0; i < line.getVertices().size(); i++){
        line.getVertices()[i].x += ofRandom(-1,1);
        line.getVertices()[i].y += ofRandom(-1,1);
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    line.draw();
    
    
    
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

    // first, make a point
    ofPoint pt;
    pt.set(x,y);
    
    // then add it to the line. 
    line.addVertex(pt);
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