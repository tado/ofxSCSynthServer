#include "ofxSCSynthServer.h"

ofxSCSynthServer::ofxSCSynthServer() {

}

void ofxSCSynthServer::boot(string hostname, unsigned int port) {

#if defined(TARGET_OSX)
    string command = "../../../../../../../addons/ofxSCSynthServer/libs/server/mac/scsynth -u " + ofToString(port);
    system(command.c_str());
#endif
    
#if defined(TARGET_WIN32)
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
#endif

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
#if defined(TARGET_OSX)
    system("pause");
#endif
#if defined(TARGET_WIN32)
	CloseHandle(pi.hThread);
	TerminateProcess(pi.hProcess, 0);
#endif
}
