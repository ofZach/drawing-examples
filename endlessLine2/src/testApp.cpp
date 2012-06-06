#include "testApp.h"



void testApp::drawPolylineInRectangle(ofPolyline & line, ofRectangle rect){
    
    
    // find the bounding rectangle of polyline
    ofRectangle box = line.getBoundingBox();
    
    // check the aspect ratio
    float boxRatio = box.width / (float)box.height;
    float rectRatio = rect.width / (float)rect.height;
    
    if (boxRatio > rectRatio){  // I am wider then higher
    
        float scale = rect.width / (float)box.width;
        ofPoint translate;
        translate.set(rect.x, rect.y + (rect.height - box.height*scale) / 2);
        
        ofPushMatrix();
        ofTranslate(translate.x, translate.y,0);
        ofScale(scale, scale, 1);
        ofTranslate(-box.x, -box.y);
        line.draw();
        ofPopMatrix();
        
    } else {
        
        float scale = rect.height / (float)box.height;
        ofPoint translate;
        translate.set(rect.x + (rect.width - box.width*scale) / 2, rect.y);
        
        ofPushMatrix();
        ofTranslate(translate.x, translate.y,0);
        ofScale(scale, scale, 1);
         ofTranslate(-box.x, -box.y);
        line.draw();
        ofPopMatrix();
        
        
    }
    
    
    
}


//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0,0,0);
    ofSetFrameRate(30);
    total.addVertex(0,0);
    angle = 0;
    angleSmooth = 0;
}

//--------------------------------------------------------------
void testApp::update(){

    
    
    if (angleDiffs.size() > 0){
        
        for (int i = 0; i < total.getVertices().size(); i++){
            total.getVertices()[i].z -= 0.5;
        }
        
        angle += angleDiffs[0];
        float dist = distances[0];
        ofPoint lastVertex = total.getVertices()[ total.getVertices().size() - 1 ];
        ofPoint newVeretx = lastVertex + ofPoint( cos(angle) * dist, sin(angle) * dist);
        angleDiffs.erase(angleDiffs.begin());
        total.addVertex(newVeretx.x, newVeretx.y);
        distances.erase(distances.begin());
        
        
        
    }
    
    
    
    catchPoint = 0.9f * catchPoint + 0.1f * total.getVertices()[total.getVertices().size()-1];
}

//--------------------------------------------------------------
void testApp::draw(){

    
    ofEnableAlphaBlending();
    
    //line.draw();
    if (ofGetMousePressed() == true){
        ofSetColor(255,255,255,100);
        line.draw();
    }
    
    if (total.getVertices().size() > 150){
        total.getVertices().erase(total.getVertices().begin());
    }
    
    if (total.getVertices().size() > 0){
        
    
        
    ofPushMatrix();
    ofTranslate(-catchPoint.x + ofGetWidth()/2, -catchPoint.y + ofGetHeight()/2);
    
    
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < total.getVertices().size(); i++){
        float pct = ofMap(i, 0, total.getVertices().size()-1, 0,1);
        ofSetColor(255,255,255,255*pct);
        glVertex3f(total.getVertices()[i].x, total.getVertices()[i].y, total.getVertices()[i].z);
    }
    glEnd();
    ofEndShape();
    
    //total.draw();
    ofPopMatrix();
    
    
    }
    
    
    for (int i = 0; i < oldLines.size(); i++){
        
        ofSetColor(50,50,50);
        ofRect(100*i,0,99,99);
        ofSetColor(255,255,255);
        drawPolylineInRectangle(oldLines[i], ofRectangle(100*i,0,99,99));
    }
    
    
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    int which = key - '0';
    if (which >= 0 && which < oldLines.size()){
        angleLine.convertFrom(oldLines[which]);
        for (int i = 0; i < angleLine.angleDiffs.size(); i++){
            angleDiffs.push_back(angleLine.angleDiffs[i]);
            distances.push_back(angleLine.distances[i]);
        }
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

    line.addVertex(ofPoint(x,y));
       
    

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    line.clear();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    //line = line.getResampledByCount(100);
    
    
    oldLines.push_back(line);
    
    
    if (oldLines.size() > 8) oldLines.erase(oldLines.begin());
    angleLine.convertFrom(line);

    
    
    for (int i = 0; i < angleLine.angleDiffs.size(); i++){
        angleDiffs.push_back(angleLine.angleDiffs[i]);
        distances.push_back(angleLine.distances[i]);
    }
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