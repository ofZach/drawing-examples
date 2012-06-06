#pragma once

#include "ofMain.h"


class timePoint {
    public: 
        float time;
        ofPoint pt;
};

class timeStroke {
public: 
    
    vector < timePoint > timePts;
    float totalTime;
    
    void draw(){
        
        ofNoFill();
        ofSetColor(255,255,255);
        ofBeginShape();
        for (int i = 0; i < timePts.size(); i++){
            ofVertex(timePts[i].pt.x, timePts[i].pt.y);
        }
        ofEndShape();
    }
    
    void draw(float time, float distanceFromTime){
        
        
        float totatLen = totalTime; 
        
        float startTime = time - distanceFromTime;
        
        
        ofSetColor(255,0,0);
        
        if (timePts.size() > 1){
            for (int i = 0; i < timePts.size()-1; i++){
                
                bool bPtaGood = false;
                bool bPtBGood = false;
                
                if (timePts[i].time >= startTime && timePts[i].time <= time){
                    bPtaGood = true;
                }
                
                if (timePts[i+1].time >= startTime && timePts[i+1].time <= time){
                    bPtBGood = true;
                }
    
                if (startTime < 0){
                    if (timePts[i].time >= (startTime + totatLen)  && timePts[i].time <= totatLen){
                        bPtaGood = true;
                    }
                    
                    if (timePts[i+1].time >= (startTime + totatLen)  && timePts[i+1].time <= totatLen){
                        bPtBGood = true;
                    }
                }
                
                if (bPtBGood == true && bPtBGood == true){
                    ofLine(timePts[i].pt, timePts[i+1].pt);
                }
            }
            
            
            
        }
        
        
        
    }
    
    
    void clear(){ timePts.clear(); };
    
    void addVertex(ofPoint pt, float t){
        timePoint ptTemp;
        ptTemp.pt = pt;
        ptTemp.time = t;
        timePts.push_back(ptTemp);
    }
    
};


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
        timeStroke stroke;
    
        vector < timeStroke > strokes;
    
        ofVideoPlayer pina;
    
    
};
