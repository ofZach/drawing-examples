#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0,0,0);
    
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void testApp::update(){

    
    
    
    for (int i = 0; i < line.getVertices().size(); i++){
        
        if (ofGetMousePressed() == false){
        float distance = ofDist(mouseX, mouseY, line.getVertices()[i].x, line.getVertices()[i].y);
        if (distance < 100){
            
            float pct = ofMap(distance, 0,100, 1,0);
            
            ofPoint diff = ofPoint(mouseX, mouseY) - ofPoint(line.getVertices()[i].x, line.getVertices()[i].y);
            diff.normalize();
            
            line.getVertices()[i].x += diff.x * 2 *  pct;
            line.getVertices()[i].y += diff.y * 2 * pct;
            
        }
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

    int nPts =  line.getVertices().size();
    line = line.getResampledByCount(nPts * 5);
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