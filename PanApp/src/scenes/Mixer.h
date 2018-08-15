#pragma once
#include "BaseScene.h"

class Mixer
{
public:
	void setup()
	{
		for (auto s : scenes)
		{
			s->setup();
		}
	}

	void update()
	{
		for (auto s : scenes)
		{
			if (s->alpha > 0)
			{
				s->update();
			}
		}
	}

	void draw()
	{
		for (auto s : scenes)
		{
			if (s->alpha > 0)
			{
				ofPushMatrix();
				ofPushStyle();
				s->draw();
				ofPopStyle();
				ofPopMatrix();
			}
		}
	}

	template<class T>
	void show()
	{
		for (auto s : scenes)
		{
			if (typeid(T).name() == typeid(*s).name())
			{
				s->alpha = 1;
			}
		}
	}

	template<class T>
	void addScene()
	{
		shared_ptr<BaseScene> s = make_shared<T>();
		scenes.emplace_back(s);
	}

	shared_ptr<BaseScene> operator[](int index)
	{
		return scenes[index];
	}
private:
	vector<shared_ptr<BaseScene> > scenes;
};