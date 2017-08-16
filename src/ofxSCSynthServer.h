#pragma once
#include "ofMain.h"
#include "ofxOsc.h"
#include <windows.h>

class ofxSCSynthServer {
public:
	ofxSCSynthServer();
	void boot(string hostname = "127.0.0.1", unsigned int port = 57110);
	void loadSynthDefsDir(string path = ".\\data\\synthdefs");
	void exit();

	PROCESS_INFORMATION pi;
	ofxOscSender sender;
};