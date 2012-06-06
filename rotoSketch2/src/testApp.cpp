#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    pina.loadMovie("pina.mov");
    cout << pina.getHeight() << endl;
    pina.play();
}

//--------------------------------------------------------------
void testApp::update(){
    
    pina.update();
}

//--------------------------------------------------------------
void testApp::draw(){

    
    
    ofSetColor(255,255,255);
    pina.draw(0,0);
    
    
    float time = pina.getPosition() * pina.getDuration();
    
    ofDrawBitmapStringHighlight(ofToString(time), 30,30);
    
    
    //stroke.draw();
    
    ofSetColor(0,0,0);
    
    stroke.totalTime = pina.getDuration();
    stroke.draw(time, 1);
    
    for (int i = 0; i < strokes.size(); i++){
        strokes[i].draw(time, 1);
        strokes[i].totalTime = pina.getDuration();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    strokes.clear();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    if (mouseY > 600){
        
        float speed = ofMap(mouseX, 0, ofGetWidth(), -2, 2);
        pina.setSpeed(speed);
        return;
        
    }
    
    float time = pina.getPosition() * pina.getDuration();
    stroke.addVertex(ofPoint(x,y), time);
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