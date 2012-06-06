#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void testApp::update(){

    
    float rotateX = 0;
    float rotateY = 0;
    float rotateZ = 0;
    
    if (ofGetKeyPressed('a')) rotateX = 1;
    if (ofGetKeyPressed('s')) rotateX = -1;
    if (ofGetKeyPressed('z')) rotateY = 1;
    if (ofGetKeyPressed('x')) rotateY = -1;
    if (ofGetKeyPressed('q')) rotateZ = 1;
    if (ofGetKeyPressed('w')) rotateZ = -1;
    
    
    
    
    for (int i = 0; i < line.getVertices().size(); i++){
        ofPoint fromCenter = line.getVertices()[i] - ofPoint(ofGetWidth()/2, ofGetHeight()/2);
        ofMatrix4x4 rotateMatrix; 
        rotateMatrix.makeRotationMatrix(1, rotateX, rotateY, rotateZ);
        ofPoint rot = fromCenter * rotateMatrix + ofPoint(ofGetWidth()/2, ofGetHeight()/2);
        line.getVertices()[i] = rot;
    }
    
    
    for (int i = 0; i < lines.size(); i++){
        for (int j = 0; j < lines[i].getVertices().size(); j++){
            ofPoint fromCenter = lines[i].getVertices()[j] - ofPoint(ofGetWidth()/2, ofGetHeight()/2);
            ofMatrix4x4 rotateMatrix; 
            rotateMatrix.makeRotationMatrix(1, rotateX, rotateY, rotateZ);
            ofPoint rot = fromCenter * rotateMatrix + ofPoint(ofGetWidth()/2, ofGetHeight()/2);
            lines[i].getVertices()[j] = rot;
        }
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    ofSetColor(0,0,0);
    
    
    /*line.draw();
    for (int i = 0; i < lines.size(); i++){
        lines[i].draw();
    }*/
    
    vector < ofPoint> crossings;
    
    if (line.getVertices().size() > 0)
    for (int i = 0; i < line.getVertices().size() -1; i++){
        ofPoint pta = line.getVertices()[i];
        ofPoint ptb = line.getVertices()[i+1];
        
        if (pta.z < 0 && ptb.z < 0){
            ofSetColor(127,127,127);
            ofLine(pta, ptb);
        } else if (pta.z >= 0 && ptb.z >= 0){
            ofSetColor(0,0,0);
            ofLine(pta, ptb);
        } else {
            
            ofPoint smallest = pta.z < ptb.z ? pta : ptb;
            ofPoint biggest = pta.z < ptb.z ? ptb : pta;
            
            float diffZ = (biggest.z - smallest.z);     // ie, (3 - -1 = 4);
            if (diffZ < 0.0001) diffZ = 0.0001;
            float pctZ = abs(smallest.z) / diffZ;
            
            ofPoint crossing = smallest + pctZ * (biggest - smallest);
            
            ofSetColor(127,127,127);
            ofLine(smallest, crossing);
            
            ofSetColor(255,0,0);
            ofCircle(crossing.x, crossing.y, 5);
            
            ofSetColor(0,0,0);
            ofLine(crossing, biggest);
            
            
        }
        
    }
    
    for (int i = 0; i < lines.size(); i++){
    
    for (int j = 0; j < lines[i].getVertices().size() -1; j++){
        ofPoint pta = lines[i].getVertices()[j];
        ofPoint ptb = lines[i].getVertices()[j+1];
        
        if (pta.z < 0 && ptb.z < 0){
            ofSetColor(127,127,127);
            ofLine(pta, ptb);
        } else if (pta.z >= 0 && ptb.z >= 0){
            ofSetColor(0,0,0);
            ofLine(pta, ptb);
        } else {
            ofPoint smallest = pta.z < ptb.z ? pta : ptb;
            ofPoint biggest = pta.z < ptb.z ? ptb : pta;
            
            float diffZ = (biggest.z - smallest.z);     // ie, (3 - -1 = 4);
            if (diffZ < 0.0001) diffZ = 0.0001;
            float pctZ = abs(smallest.z) / diffZ;
            
            ofPoint crossing = smallest + pctZ * (biggest - smallest);
            
            ofSetColor(127,127,127);
            ofLine(smallest, crossing);
            
            ofSetColor(255,0,0);
            ofCircle(crossing.x, crossing.y, 5);
            
            ofSetColor(0,0,0);
            ofLine(crossing, biggest);
            
        }
        
    }
    }
    
    ofDrawBitmapStringHighlight("q,w,a,s,z,x to rotate", ofPoint(50,50));
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if (key == ' '){
        lines.clear();
        line.clear();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

    line.addVertex(ofPoint(x,y, 0.01));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    line.clear();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

    if (line.getVertices().size() > 1) lines.push_back(line);
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