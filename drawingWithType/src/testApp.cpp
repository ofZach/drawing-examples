#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    font.loadFont("Bangla Sangam MN.ttf", 64);
    
    ofBackground(255,255,255);
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    ofEnableAlphaBlending();
    
    float widthSmooth = 1;
    float angleSmooth;
    
    ofPoint lastLetter;
    float distanceToNextLetter = 20;
    
    
    string temp = "Yea I'm out that Brooklyn, now I'm down in TriBeCa right next to Deniro, but I'll be hood forever I'm the new Sinatra, and... since I made it here    I can make it anywhere, yea, they love me everywhere";
    
    
    int count = 0;
    
    for (int i = 0;  i < line.getVertices().size(); i++){
        
        
        
        
        int me_m_one = i-1;
        int me_p_one = i+1;
        if (me_m_one < 0) me_m_one = 0;
        if (me_p_one ==  line.getVertices().size()) me_p_one =  line.getVertices().size()-1;
        
        ofPoint diff = line.getVertices()[me_p_one] - line.getVertices()[me_m_one];
        float angle = atan2(diff.y, diff.x);
        
        if (i == 0) angleSmooth = angle;
        else {
            
            angleSmooth = ofLerpDegrees(angleSmooth, angle, 1.0);
            
        }
        
        
        float dist = diff.length();
        
        float w = ofMap(dist, 0, 20, 1.1, 0.3, true);
        
        widthSmooth = 0.9f * widthSmooth + 0.1f * w;
        
        ofPoint offset;
        
        
        bool bDrawLetter = false;
        if (i == 0){
            bDrawLetter = true;
        } else if ( (line.getVertices()[i] - lastLetter).length() >distanceToNextLetter) {
            bDrawLetter = true;
            
        }
        
        if (bDrawLetter == true){
            
            
            
            char c = temp[count];
            count ++;
            count %= temp.size();
            string s = "";
            s += c;
            
            ofRectangle rect = font.getStringBoundingBox(s, 0, 0);
            
            ofSetColor(0,0,0);
            
            ofPushMatrix();
            ofTranslate( line.getVertices()[i].x,  line.getVertices()[i].y, 0);
            ofRotate(angleSmooth * RAD_TO_DEG);
            ofScale(widthSmooth, widthSmooth, 1);
            font.drawString(s, -rect.x - rect.width/2.0, -rect.y - rect.height/2.0);
            ofPopMatrix();
            
            lastLetter = line.getVertices()[i];
            distanceToNextLetter =  (rect.x + rect.width)*widthSmooth*0.7;
        }
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