#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);

	//create new sc server
	server = new ofxSCSynthServer();
	//boot scsynth
	server->boot();
}

//--------------------------------------------------------------
void ofApp::update() {
	if (synth != NULL && synth->created) {
		float freq = ofMap(mouseY, 0, ofGetHeight(), 1000, 20);
		synth->set("freq", freq);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);
	ofDrawBitmapString("[d] : load synthdefs", 20, 20);
	ofDrawBitmapString("[a] : create new synth", 20, 30);
	ofDrawBitmapString("[s] : stop synth", 20, 40);
}

void ofApp::exit() {
	server->exit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == 'd') {
		//load synthdef files
		server->loadSynthDefsDir();
	}
	if (key == 'a') {
		//start synth
		synth = new ofxSCSynth("sine");
		synth->create();
	}
	if (key == 's') {
		//stop synth
		synth->free();
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
