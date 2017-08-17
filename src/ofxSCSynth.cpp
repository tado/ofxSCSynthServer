#include "ofxSCSynth.h"

ofxSCSynth::ofxSCSynth(string name, string hostname, unsigned int port){
	this->name = name;
	this->hostname = hostname;
	this->port = port;
	created = false;
	synthId = ofGetFrameNum();
	sender.setup(hostname, port);
}

ofxSCSynth::~ofxSCSynth(){
}

void ofxSCSynth::create(int position, int groupID) {
	ofxOscBundle b;
	ofxOscMessage m;
	m.setAddress("/s_new");
	m.addStringArg(name);
	m.addIntArg(synthId);
	m.addIntArg(0);
	m.addIntArg(0);
	sender.sendMessage(m);
	created = true;
}

void ofxSCSynth::free() {
	ofxOscMessage m;
	m.setAddress("/n_free");
	m.addInt32Arg(synthId);
	sender.sendMessage(m);
}

void ofxSCSynth::set(string arg, double value)
{
	if (created){
		ofxOscMessage m;
		m.setAddress("/n_set");
		m.addIntArg(synthId);
		m.addStringArg(arg);
		m.addFloatArg(value);
		sender.sendMessage(m);
	}
}

void ofxSCSynth::set(string arg, int value)
{
	if (created){
		ofxOscMessage m;
		m.setAddress("/n_set");
		m.addIntArg(synthId);
		m.addStringArg(arg);
		m.addIntArg(value);
		sender.sendMessage(m);
	}
}