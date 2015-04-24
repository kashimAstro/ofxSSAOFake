#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSSAOFake.h"

class ofApp : public ofBaseApp {
	public:
		ofxPanel gui;
		ofParameter<float> dark;
		ofParameter<ofVec2f> dis;


		int w,h;
		ofxSSAOFake ssao;
		ofImage img;

		void setup();
	        void darkChange(float & value);
		void noiseChange(ofVec2f & value);
		void update();
		void draw();
		void keyPressed(int key);
};
