#pragma once
#include <Framwork/Game.h>

namespace anvilHM 
{
	class Font;
	class Text;
}

class SpaceShooter : public anvilHM::Game
{
	public:	
		SpaceShooter() = default;
		~SpaceShooter() = default;

	// Inherited via Game
		virtual void Initialize() override;

		virtual void Shutdown() override;

		virtual void Update() override;

		virtual void Draw(anvilHM::Renderer& renderer) override;
	private:
		float m_spawnTimer = 4;
		
		std::unique_ptr<anvilHM::Font> m_font;
		std::unique_ptr<anvilHM::Text> m_titleText;
		std::unique_ptr<anvilHM::Text> m_scoreText;
		std::unique_ptr<anvilHM::Text> m_health;
		std::unique_ptr<anvilHM::Text> m_death;

};