#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(50);
    w=ofGetWidth();
    h=ofGetHeight();

    ssao.init(w,h);

    ofDisableArbTex();
    img.loadImage("img.jpg");

    gui.setup();
    gui.add(dark.set("dark ssao",0.16f,0.f,1.f));
    gui.add(disorder.set("disorder ssao",0.f,0.f,255.f));
    dark.addListener(this,&ofApp::darkChange);
    disorder.addListener(this,&ofApp::noiseChange);

    ssao.setDark(dark.get());
}

void ofApp::darkChange(float & value){
    ssao.setDark(value);
}

void ofApp::noiseChange(float & value){
    ssao.prepareNoiseMap(250,250,value);
}

void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

void ofApp::draw(){
    ofBackgroundGradient(255,0);

    ssao.setOutputScene(img);
    ssao.draw();

        ssao.noiseMap.draw(0,0);

    gui.draw();
}

void ofApp::keyPressed(int key){

}
