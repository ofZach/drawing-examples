#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "timePoint.h"
#include "timePointRecorder.h"


typedef struct {
    
    timePointRecorder TPR;
    ofSoundPlayer snd;
    float startTime;
    
} sndStroke;


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

	
		timePointRecorder		TPR;
        
        ofSoundPlayer snd;
    
        ofPolyline line;
    
    
        vector < sndStroke > strokes;
    
        ofPoint prevPos;    // prev mouseX/mouseY
	
};

#endif
