#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);

	ofBackground(255, 255, 255);
	TPR.setup();
	playbackStartTime = 0;
    
	loopingSound.loadSound("drawbar_c4_a.aif");
	loopingSound.setVolume(0);
	loopingSound.setLoop(true);
	loopingSound.play();
	
  
}


//--------------------------------------------------------------
void testApp::update(){

    
    if (ofGetMousePressed()){
        
        ofPoint vel = ofPoint(mouseX, mouseY) - prevPos;
        
        // since velocity is a line, we want to know how long it is. 
        float lengthOfVel = ofDist(0,0,vel.x, vel.y);
        
        float soundVolume = ofMap(lengthOfVel, 0,40, 0,1);
        float mixVol = 0.1 * soundVolume + 0.9 * loopingSound.getVolume();
		loopingSound.setVolume(mixVol);
        
        float pitch = ofMap(mouseY, 0, (float)ofGetHeight(), 2.5, 0.1);
        float mixPitch = 0.1 * loopingSound.getSpeed() + 0.9 * pitch;
		loopingSound.setSpeed(mixPitch);
		
    }

    
     prevPos.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::draw(){

    
	// -------------------------- draw the line
	TPR.draw();
	
	// -------------------------- draw the point at the current time
	if (TPR.bHaveADrawing()){			// if we have a drawing to work with
		
		// figure out what time we are at, and make sure we playback cyclically (!)
		// use the duration here and make sure our timeToCheck is in the range of 0 - duration
		float timeToCheck = ofGetElapsedTimef() - playbackStartTime;
		while (timeToCheck > TPR.getDuration() && TPR.getDuration() > 0){
			timeToCheck -= TPR.getDuration();
		}
		
		// get the position and velocity at timeToCheck
		ofPoint pos = TPR.getPositionForTime(timeToCheck);
		ofPoint vel = TPR.getVelocityForTime(timeToCheck);
		
		// since velocity is a line, we want to know how long it is. 
		float lengthOfVel = ofDist(0,0,vel.x, vel.y);
		
		float soundVolume = ofMap(lengthOfVel, 0,40, 0,1);
        float mixVol = 0.1 * soundVolume + 0.9 * loopingSound.getVolume();
		loopingSound.setVolume(mixVol);
		
		float pitch = ofMap(pos.y, 0, (float)ofGetHeight(), 2.5, 0.1);
        float mixPitch = 0.1 * loopingSound.getSpeed() + 0.9 * pitch;
		loopingSound.setSpeed(mixPitch);
		
		
		ofFill();
		ofSetColor(255,0,0);
		ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
		
		
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
	TPR.addPoint(x,y);
    
       
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	TPR.startDrawing(x,y);
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	TPR.endDrawing();
	playbackStartTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}



