#include "GameObject.h"
#include "Component.h"

GameObject::GameObject()
	: isDead(false)
{
	box = Rect(0, 0, 0, 0);
}

GameObject::~GameObject()
{
#if true
	for (auto go : components)
		delete go;

	components.clear();

#else
	components.clear();
#endif
}

void GameObject::Update(float dt)
{
#if true
	for (auto go : components)
		go->Update(dt);
#else
	for (auto&& go : components)
		go->Update(dt);
#endif
}

void GameObject::Render()
{
#if true
	for (auto go : components)
		go->Render();
#else
	for (auto&& go : components)
		go->Render();
#endif
}

void GameObject::AddComponent(Component* cpt)
{
#if true
	components.push_back(std::move(cpt));
#else
	components.push_back(std::move(std::unique_ptr<Component>(cpt)));
#endif
}

void GameObject::RemoveComponent(Component* cpt)
{
#if true
	components.erase(std::remove_if(components.begin(), components.end(), [cpt](auto const& go) { return go == cpt; }), components.end());
#else
	components.erase(std::remove_if(components.begin(), components.end(), [cpt](auto const& go) { return go.get() == cpt; }), components.end());
#endif
}

Component* GameObject::GetComponent(std::string type)
{
#if true
	for (auto& go : components)
	{
		if (go->Is(type))
			return go;
	}
#else
	for (auto& go : components)
	{
		if (go->Is(type))
			return go.get();
	}
#endif

	return nullptr;
}
