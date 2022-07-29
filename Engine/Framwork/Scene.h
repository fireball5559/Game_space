#pragma once
#include<list>
#include <memory>
#include "Actor.h"

namespace anvilHM 
{	
	//class Actor;
	class Renderer;
	class Game;

	class Scene 
	{
	public:
		Scene() = default;
		~Scene() = default;
		Scene(Game* game) : m_game(game) {};
		void Update();
		void draw(Renderer& render);
		void Add(std::unique_ptr<Actor> actor);
		template<typename T>
		T* GetActor();
		Game* GetGame() {return m_game; }
	private:
		std::list<std::unique_ptr<Actor>> m_actors;
		Game* m_game;
	};

	template<typename T>
	inline T* Scene::GetActor()
	{
		//int i = 5;
		//float f = static_cast<float>(i);//looks pretty i guess?//does this 5 ->5.0f
		for (auto& actor : m_actors) {
			T* result = dynamic_cast<T*>(actor.get());//tries to cast the T to player
				if (result) { return result; }
		}
		return nullptr;
	}

}
