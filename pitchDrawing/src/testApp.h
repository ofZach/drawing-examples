#pragma once

#include "ofMain.h"


#define USE_AUBIO               // don't have aubio compiled for windows. 

#ifdef USE_AUBIO
    #include "aubioAnalyzer.h"
#endif

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
		
    
        void audioReceived		(float * input, int bufferSize, int nChannels); 
    
    
        float pitch;
        float volume;
        float * left, * right;
        bool bLoudEnough;
        float pitchSmooth;      // non aubio needs some love -- works well w/ whisteling. 
    
        #ifdef USE_AUBIO
            aubioAnalyzer AA;
        #endif
        
        vector < float > angleDiffs;
        vector < float > distances;
        ofPolyline total;
        float angle;
        float angleSmooth;
        ofPoint catchPoint;

    
        
    
};
