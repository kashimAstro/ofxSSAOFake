#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSSAOFake.h"

class xApp : public ofBaseApp {
	public:
		ofxPanel gui;
		ofParameter<float> dark;
		ofParameter<float> disorder;

		int w,h;
		ofxSSAOFake ssao;
		ofImage img;

		void setup(){
			ofSetFrameRate(50);

			w=ofGetWidth();
			h=ofGetHeight();

			ssao.init(w,h);

			ofDisableArbTex();
			img.loadImage("img.jpg");

		        gui.setup();
		        gui.add(dark.set("dark ssao",0.16f,0.f,1.f));
		        gui.add(disorder.set("disorder ssao",0.f,0.f,255.f));
	        	dark.addListener(this,&xApp::darkChange);
		        disorder.addListener(this,&xApp::noiseChange);

		        ssao.setDark(dark.get());
        	}

	        void darkChange(float & value){
	            ssao.setDark(value);
	        }

		void noiseChange(float & value){
		    ssao.prepareNoiseMap(250,250,value);
		}

		void update(){
			ofSetWindowTitle(ofToString(ofGetFrameRate()));
		}

		void draw(){
			ofBackgroundGradient(255,0);
			
			ssao.setOutputScene(img);
			ssao.draw();

		        ssao.noiseMap.draw(0,0);

			gui.draw();
		}

		void keyPressed(int key){

		}
};

int main( ){
	ofSetupOpenGL(1280, 720, OF_WINDOW);
	ofRunApp(new xApp());

}
