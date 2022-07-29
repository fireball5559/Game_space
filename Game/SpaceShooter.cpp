#include "SpaceShooter.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
//#include <memory> //incase of something for scene

void SpaceShooter::Initialize()
{
	m_scene = std::make_unique<anvilHM::Scene>(this);

	//create assets
	anvilHM::g_audio.AddAudio("Laser", "Laser.wav");
	anvilHM::g_audio.AddAudio("Explosion", "Explosions.wav");
	anvilHM::g_audio.AddAudio("Music", "Background.wav");

	

	//Font/title
	m_font = std::make_unique<anvilHM::Font>("Fonts/later", 24);//
	m_titleText = std::make_unique<anvilHM::Text>(m_font.get());
	m_titleText->Create(anvilHM::g_renderer, "Time TO GO IN", { 255,255,0,255});
	//health
	m_health = std::make_unique<anvilHM::Text>(m_font.get());
	m_health->Create(anvilHM::g_renderer, "0", {255,255,0,255});
	//Score
	m_scoreText = std::make_unique<anvilHM::Text>(m_font.get());
	m_scoreText->Create(anvilHM::g_renderer, "00000", { 255,255,255,255 });
	//Death
	m_death = std::make_unique<anvilHM::Text>(m_font.get());


	//
	//create ACTOR
	anvilHM::Transform transform;
	transform.position = { 400,300 };
	transform.rotation = 0;
	transform.scale = 3;
	std::unique_ptr<player> Player = std::make_unique<player>(anvilHM::Model{ "Model.txt" }, transform);
	p_Health = Player->GetHealth();

	m_scene->Add(std::move(Player));//since it is a unique now you have to use -> instead of .

}

void SpaceShooter::Shutdown()
{
	//delete Font

}

void SpaceShooter::Update()
{
	//spawn update
	m_spawnTimer -= anvilHM::g_time.deltaTime;
	if (m_spawnTimer <= 0)
	{
		anvilHM::Transform transform;
		transform.position.x = anvilHM::randomf(100);
		transform.position.y = anvilHM::randomf(100);
		transform.rotation = anvilHM::randomf(math::TwoPi);
		transform.scale = 3;
		std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(anvilHM::Model{ "Enemy.txt" }, transform, 10.0f);
		m_scene->Add(std::move(enemy));
		m_spawnTimer = 2;//could do a random 
	}
	m_scene->Update();

	//update score text;
	m_scoreText->Create(anvilHM::g_renderer, std::to_string(m_score), { 255,255,255,255 });
	//update Health if hit
	//notworking
	//std::cout << p_Health;
	
	
	if (p_Health <= 0)
	{
		m_death->Create(anvilHM::g_renderer, "YOU HAVE DIED", { 255,255,255,255 });
	}
		m_health->Create(anvilHM::g_renderer, std::to_string((int)p_Health), { 255,255,255,255 });
}

void SpaceShooter::Draw(anvilHM::Renderer& renderer)
{
	//Render Game Objects
	m_scene->draw(renderer);

	m_titleText->Draw(renderer, { 350,20 });
	m_scoreText->Draw(renderer, { 40,30 });
	m_health->Draw(renderer, { 700,20 });
	if (p_Health <=0 ) 
	{
		m_death->Draw(renderer, { 400,200 });
	}
	
}
