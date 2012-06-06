#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0,0,0);
    
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void testApp::update(){

    
    if (ofGetMousePressed() == true){
        
        // first, make a point
        ofPoint pt;
        pt.set(mouseX, mouseY);
        
        // then add it to the line. 
        line.addVertex(pt);
    }
    
    
    for (int i = 0; i < line.getVertices().size(); i++){
        
        if (ofGetMousePressed() == true){
            ofPoint diff = ofPoint (mouseX, mouseY) - ofPoint(ofGetWidth()/2, ofGetHeight()/2);
            line.getVertices()[i].x -= diff.x * 0.05;
            line.getVertices()[i].y -= diff.y * 0.05;
        }
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