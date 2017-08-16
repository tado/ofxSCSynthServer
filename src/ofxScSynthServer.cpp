#include "ofxSCSynthServer.h"

ofxSCSynthServer::ofxSCSynthServer() {

}

void ofxSCSynthServer::boot(string hostname, unsigned int port) {
	// start scsynth
	STARTUPINFOA si;
	GetStartupInfoA(&si);

	string strCmd = "..\\..\\..\\..\\addons\\ofxSCSynthServer\\libs\\server\\win\\scsynth.exe -u " + ofToString(port);
	LPSTR command = LPSTR(strCmd.c_str());

	CreateProcessA(
		NULL,
		command,
		NULL,
		NULL,
		FALSE,
		NULL,
		NULL,
		NULL,
		&si,
		&pi
	);

	//OSC setup
	sender.setup(hostname, port);
}

void ofxSCSynthServer::loadSynthDefsDir(string path) {
	//load syntdef
	ofxOscMessage m;
	m.setAddress("/d_loadDir");
	m.addStringArg(path);
	sender.sendMessage(m);
}

void ofxSCSynthServer::exit() {
	CloseHandle(pi.hThread);
	TerminateProcess(pi.hProcess, 0);
}