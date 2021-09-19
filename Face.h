#pragma once

#include <string>
#include "Component.h"

class Face 
	: public Component
{
public:
	Face(GameObject& associated);

public:
	void Damage(int damage);

public:
	void Update(float dt) override  {};
	void Render() override {};

public:
	bool Is(std::string type) override	{ return type.compare("Face") == 0;	}

private:
	int hitPoints;
};

