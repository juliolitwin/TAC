#pragma once

#include <string>
#include "GameObject.h"

class Component
{
public:
	Component(GameObject& go);
	virtual ~Component();

public:
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;

public:
	virtual bool Is(std::string type) = 0;

protected:
	GameObject& associated;
};

