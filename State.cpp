#include "State.h"

#include <math.h>
#include <iostream>

#include "Music.h"
#include "Sound.h"
#include "Sprite.h"
#include "Face.h"
#include "Vec2.h"
#include "Rect.h"
#include "TileSet.h"
#include "TileMap.h"

State::State()
{
	quitRequested = false;

	LoadAssets();
}

State::~State()
{
	objectArray.clear();
}

void State::LoadAssets()
{
	std::unique_ptr<GameObject> go = std::unique_ptr<GameObject>(new GameObject());
	go->box.x = 0;
	go->box.y = 0;
	go->AddComponent(new Sprite(*go, ".\\data\\img\\ocean.jpg"));
	go->AddComponent(new Music(*go, ".\\data\\audio\\stageState.ogg"));
	objectArray.push_back(std::move(go));

	std::unique_ptr<GameObject> go2 = std::unique_ptr<GameObject>(new GameObject());
	go2->box.x = 0;
	go2->box.y = 0;
	TileSet* tileSet = new TileSet(*go2, 64, 64, ".\\data\\img\\tileset.png");
	TileMap* tileMap = new TileMap(*go2, ".\\data\\map\\tileMap.txt", tileSet);
	go2->AddComponent(tileMap);
	
	objectArray.push_back(std::move(go2));
}

void State::Update(float dt)
{
	// 1. Process input.
	Input();

	// 2. Process go's - update.
	for (auto&& obj : objectArray)
		obj->Update(dt);

	// 3. Process go's - remove.
	objectArray.erase(
		std::remove_if(objectArray.begin(), objectArray.end(), [](auto const& go)
			{
				return go.get()->IsDead();
			}),
		objectArray.end());
}

void State::Render()
{
	for (auto&& obj : objectArray)
		obj->Render();
}

void State::AddObject(int mouseX, int mouseY)
{
	std::unique_ptr<GameObject> go = std::unique_ptr<GameObject>(new GameObject());
	auto spr = new Sprite(*go, ".\\data\\img\\penguinface.png");

	go->box.x = mouseX;
	go->box.y = mouseY;
	go->box.h = spr->GetHeight();
	go->box.w = spr->GetWidth();

	go->AddComponent(spr);
	go->AddComponent(new Sound(*go, ".\\data\\audio\\boom.wav"));
	go->AddComponent(new Face(*go));

	objectArray.push_back(std::move(go));
}

void State::Input()
{
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) 
	{

		// Se o evento for quit, setar a flag para terminação
		if (event.type == SDL_QUIT)
		{
			quitRequested = true;
		}

		// Se o evento for clique...
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for (int i = objectArray.size() - 1; i >= 0; --i)
			{
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*)objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if (objectArray[i]->box.Contains({ (float)mouseX, (float)mouseY })) 
				{
					Face* face = (Face*)go->GetComponent("Face");
					if (nullptr != face) 
					{
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if (event.type == SDL_KEYDOWN)
		{
			// Se a tecla for ESC, setar a flag de quit
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quitRequested = true;
			}
			// Se não, crie um objeto
			else
			{
				Vec2 objPos = Vec2(200, 0).GetRotated(-M_PI + M_PI * (rand() % 1001) / 500.0) + Vec2((float)mouseX, (float)mouseY);
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}