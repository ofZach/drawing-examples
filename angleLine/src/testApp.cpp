#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0,0,0);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    
    
    line.draw();
    
    
    for (int i = 0; i < alines.size(); i++){
        
        alines[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    alines.clear();
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
    
    angleLine.convertFrom(line);
    alines.push_back(angleLine);
    line.clear();
    
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