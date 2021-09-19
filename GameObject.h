#pragma once

#include <memory>
#include <string>
#include <vector>
#include "Rect.h"

class Component;

class GameObject
{
public:
	GameObject();
	~GameObject();

public:
	void Update(float dt);
	void Render();

public:
	bool IsDead() { return isDead; }
	void RequestDelete() { isDead = true; }

public:
	void AddComponent(Component* cpt);
	void RemoveComponent(Component* cpt);
	Component* GetComponent(std::string type);

public:
	Rect box;

private:
	bool isDead;

#if true
	std::vector<Component*> components;
#else
	std::vector<std::unique_ptr<Component>> components;
#endif
};

