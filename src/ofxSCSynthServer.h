#pragma once
#include "ofMain.h"
#include "ofxOsc.h"

#if defined(TARGET_WIN32)
#include <windows.h>
#endif

class ofxSCSynthServer {
public:
	ofxSCSynthServer();
	void boot(string hostname = "127.0.0.1", unsigned int port = 57110);
#if defined(TARGET_OSX)
	void loadSynthDefsDir(string path = "../../../data/synthdefs");
#endif
#if defined(TARGET_WIN32)
	void loadSynthDefsDir(string path = ".\\data\\synthdefs");
#endif
	void exit();

	ofxOscSender sender;

#if defined(TARGET_OSX)
	pid_t pid;
#endif

#if defined(TARGET_WIN32)
	PROCESS_INFORMATION pi;
#endif
};
