#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSSAOFake.h"

class ofApp : public ofBaseApp {
	public:
		ofxPanel gui;
		ofParameter<float> dark;
		ofParameter<float> disorder;

		int w,h;
		ofxSSAOFake ssao;
		ofImage img;

		void setup();
	        void darkChange(float & value);
		void noiseChange(float & value);
		void update();
		void draw();
		void keyPressed(int key);
};
