#pragma once
#include <memory>
namespace anvilHM {

	//Forward
	class Renderer;
	class Scene;
	class Game
	{
	public:
		Game() = default;
		virtual ~Game() = default;

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;

		virtual void Update() = 0;
		virtual void Draw(Renderer& renderer) = 0;//pure virtual,
		int GetScore() { return m_score; }
		void AddPoints(int points) { m_score += points; }
		float adjustHealth(float health) {return p_Health -= health; };
		float getHealth() { return p_Health; }
	protected:
		std::unique_ptr<Scene> m_scene;
		int m_score = 0;
		float p_Health = 0;


	};
}