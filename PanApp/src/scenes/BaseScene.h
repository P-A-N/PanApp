#pragma once

class BaseScene
{
	friend class Mixer;
public:
	virtual void setup() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
private:
	float alpha = 0;
};