#include "ofxSCSynthServer.h"

ofxSCSynthServer::ofxSCSynthServer() {
    
}

void ofxSCSynthServer::boot(string hostname, unsigned int port) {
    
#if defined(TARGET_OSX)
    string command = "../../../../../../../addons/ofxSCSynthServer/libs/server/mac/scsynth";
    string arg = "-u " + ofToString(port);
    pid_t parent = getpid();
    pid_t child = fork();
    int status;
    if (child == -1){
        cout << "error, failed to boot scsynth" << endl;
    } else if (child > 0) {
        pid = child;
        waitpid(child, &status, 1);
    } else {
        execlp(command.c_str(), "scsynth", "-u", ofToString(port).c_str(), NULL);
    }
    ofSleepMillis(4000);
#endif
    
#if defined( __WIN32__ ) || defined( _WIN32 ) || defined( __WIN64__ ) || defined( _WIN64 )
    // start scsynth
    STARTUPINFOA si;
    GetStartupInfoA(&si);
    
    string strCmd = "..\\..\\..\\..\\addons\\ofxSCSynthServer\\libs\\server\\win\\scsynth.exe -u " + ofToString(port);
    LPSTR command = LPSTR(strCmd.c_str());
    
    CreateProcessA(NULL, command, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, 2000);
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
    kill(pid, SIGKILL);
#endif
    
#if defined( __WIN32__ ) || defined( _WIN32 ) || defined( __WIN64__ ) || defined( _WIN64 )
    CloseHandle(pi.hThread);
    TerminateProcess(pi.hProcess, 0);
#endif
}
