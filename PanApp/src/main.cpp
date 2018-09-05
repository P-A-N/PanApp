#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofJson json = ofLoadJson("setting.json");
	ofApp::RunMode mode = ofApp::SANDBOX;
	if (json.at("is_production"))
		mode = ofApp::PRODUCTION;

	int width = 1920;
	int height = 1080;
	ofGLFWWindowSettings s;
	s.setSize(width, height);
	s.setGLVersion(4, 1);
	if (mode == ofApp::PRODUCTION) {
		s.setPosition(glm::vec2(0, 0));
		//s.windowMode = OF_FULLSCREEN;
		s.monitor = 0;
		s.decorated = false;
		s.multiMonitorFullScreen = true;
	}
	ofCreateWindow(s);

	ofRunApp(new ofApp(mode));
}
