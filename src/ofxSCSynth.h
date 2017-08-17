#pragma once
#include "ofMain.h"
#include "ofxOsc.h"

class ofxSCSynth {
public:	
	ofxSCSynth(string name, string hostname = "127.0.0.1", unsigned int port = 57110);
	~ofxSCSynth();
    string getName() {return name;}
	void create(int position = 0, int groupID = 1);
	void free();
	void set(string arg, double value);
	void set(string arg, int value);
		
	string name;
	string hostname;
	unsigned int port;
	int synthId;
	bool created;
	ofxOscSender sender;
};
