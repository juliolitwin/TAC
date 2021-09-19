#include "Face.h"
#include "Sound.h"

Face::Face(GameObject& associated)
	: Component(associated)
	, hitPoints(30)
{
}

void Face::Damage(int damage)
{
	hitPoints -= damage;
	if (hitPoints <= 0)
	{
		Sound* sound = (Sound*)associated.GetComponent("Sound");
		if (sound != nullptr)
			sound->Play();

		associated.RequestDelete();
	}
}
