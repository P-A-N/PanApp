#pragma once
#include "BaseScene.h"
#include "ofMain.h"

class PixelSort : public BaseScene
{
public:
	void setup()
	{
		shader.load("shader/pixsort");
		cam.listDevices();
	}

	void update()
	{

	}

	void draw()
	{
		ofSetColor(ofColor::red);
		shader.begin();
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		shader.end();
	}
private:
	ofShader shader;
	ofVideoGrabber cam;
	
};