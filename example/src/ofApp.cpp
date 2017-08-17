#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	scsynth = new ofxSCSynthServer();
    
    //boot scsynth
	scsynth->boot();
    //wait for boot...
	ofSleepMillis(5000);
    //load synthdef files
	scsynth->loadSynthDefsDir();
    //OSC setup
    sender.setup("127.0.0.1", 57110);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::exit() {
	scsynth->exit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'a')	{
        //start synth
        ofxOscMessage m;
        m.setAddress("/s_new");
        m.addStringArg("sine");
        m.addInt32Arg(1000);
        m.addInt32Arg(0);
        m.addInt32Arg(0);
        sender.sendMessage(m);
    }
    if (key == 's')	{
        //stop synth
        ofxOscMessage m;
        m.setAddress("/n_free");
        m.addInt32Arg(1000);
        sender.sendMessage(m);
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
