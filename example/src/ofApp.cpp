#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//create new sc server
	server = new ofxSCSynthServer();
	//boot scsynth
	server->boot();

	//create synth (using ofxSuperCollider)
	synth = new ofxSCSynth("sine_harmonic");
	synth->create(0, 0);

	ofBackground(0, 20, 50);
	ofSetBackgroundAuto(false);
}

void ofApp::exit() {
	synth->free();
    server->exit();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofEnableAlphaBlending();
	ofSetColor(0, 20, 50, 2);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	if (button == 0) {
		synth->set("freq", x + 40);
		synth->set("amp", 1.0f - (float)y / ofGetHeight());
		synth->set("pan", (float)x / ofGetHeight() - 0.5f);

		ofSetColor(255, 255, 255, 100);
		ofCircle(x, y, 10 * (1.0 - (float)y / ofGetHeight()));
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (button == 0) {
		this->mouseDragged(x, y, button);
		synth->set("amp", 0.8f);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	synth->set("amp", 0.1f);
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
