#pragma once

#include "ofMain.h"

#include "ofxSimpleSlider.h"





//-------------------------------------------------
class timePoint {
    public: 
        float time;
        ofPoint pt;
};


//-------------------------------------------------
class timeStroke {
public: 
    
    vector < timePoint > timePts;
    
    float width;
    
    timeStroke(){
        width = 10;

    }
    
    void drawPolyineThick( ofPolyline & line, int thickness){
    
        ofMesh meshy;
        meshy.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        
        float widthSmooth = 10;
        float angleSmooth;
        
        for (int i = 0;  i < line.getVertices().size(); i++){
            int me_m_one = i-1;
            int me_p_one = i+1;
            if (me_m_one < 0) me_m_one = 0;
            if (me_p_one ==  line.getVertices().size()) me_p_one =  line.getVertices().size()-1;
            ofPoint diff = line.getVertices()[me_p_one] - line.getVertices()[me_m_one];
            float angle = atan2(diff.y, diff.x);
            float dist = diff.length();
            ofPoint offset;
            offset.x = cos(angle + PI/2) * thickness;
            offset.y = sin(angle + PI/2) * thickness;
            meshy.addVertex(  line.getVertices()[i] +  offset );
            meshy.addVertex(  line.getVertices()[i] -  offset );
        }
        
        meshy.draw();
        
        
    }

    
    
    void draw(){
        
        ofNoFill();
        ofSetColor(255,255,255);
        ofBeginShape();
        for (int i = 0; i < timePts.size(); i++){
            ofVertex(timePts[i].pt.x, timePts[i].pt.y);
        }
        ofEndShape();
    }
    
    
    void draw(float time, float distanceFromTime, float totalTime){
        
        
        // this is simpler logic!
        
        /*float startTime = time - distanceFromTime;
        
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
                    if (timePts[i].time >= (startTime + totalTime)  && timePts[i].time <= totalTime){
                        bPtaGood = true;
                    }
                    
                    if (timePts[i+1].time >= (startTime + totalTime)  && timePts[i+1].time <= totalTime){
                        bPtBGood = true;
                    }
                }
                
                if (bPtBGood == true && bPtBGood == true){
                    ofLine(timePts[i].pt, timePts[i+1].pt);
                }
            }
            
            
            
        }*/
        
        float startTime = time - distanceFromTime;
        
        // ok so we could have time prior to 0 (ie, time = 1, distance from time = 2, start time = -1);
        // so we do some funky-ish logic here. 
        
        
        if (timePts.size() > 1){
            ofPolyline line;
                for (int i = -timePts.size(); i < timePts.size(); i++){
                    int who;
                    float tt;
                    if (i < 0){
                        who += timePts.size();
                        tt = timePts[who].time - totalTime;
                    } else {
                        who = i;
                        tt = timePts[who].time;;
                        
                    }
                    
                    if (tt >= startTime && tt <= time){
                        line.addVertex(timePts[i].pt);
                    } else {
                        if (line.getVertices().size() > 0){
                            drawPolyineThick(line, width);
                            line.clear();
                        }
                    }
                    
                }
        }
        
//        if (timePts.size() > 1){
//            
//            ofPolyline line;
//            for (int i = 0; i < timePts.size(); i++){
//                if (timePts[i].time >= startTime && timePts[i].time <= time){
//                    line.addVertex(timePts[i].pt);
//                } else {
//                    if (line.getVertices().size() > 0){
//                        drawPolyineThick(line, width);
//                        line.clear();
//                    }
//                }
//            }
//            
//            
//            if (line.getVertices().size() > 0){
//                drawPolyineThick(line, width);
//                line.clear();
//            }
//            
//            if (startTime < 0){
//                for (int i = 0; i < timePts.size(); i++){
//                    if (timePts[i].time >= (startTime + totalTime)  && timePts[i].time <= totalTime){
//                        line.addVertex(timePts[i].pt);
//                    }else {
//                        if (line.getVertices().size() > 0){
//                            drawPolyineThick(line, width);
//                            line.clear();
//                        }
//                    }
//                
//                }
//                
//                if (line.getVertices().size() > 0){
//                    drawPolyineThick(line, width);
//                    line.clear();
//                }
//            }
//        }
                
                
                
                    //ofLine(timePts[i].pt, timePts[i+1].pt);
            
            
            
            
        
        
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
    
        ofxSimpleSlider slider;
    
    
};
