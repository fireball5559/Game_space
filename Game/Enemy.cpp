#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "Engine.h"

void Enemy::OnCollision(Actor* other)
{
	//could make tags to label how they were hurt and if they should be hurt by it
	// so bullet tag enemy bullet tag friendly
	if (dynamic_cast<Bullet*>(other) && other->GetTag()=="player")
	{
		m_health -= dynamic_cast<Bullet*>(other)->GetDamage();
		if (m_health <= 0) { 
			m_destroy = true;
			m_scene -> GetGame()->AddPoints(100);
			anvilHM::g_audio.PlayAudio("Explosion.wav");

		};

	}
}

void Enemy::Initialize()
{
	m_fireTimer = anvilHM::randomf(2, 6);
	m_speed = anvilHM::randomf(20, 150);
}

void Enemy::Update()
{
	//coolDown
	m_fireTimer -= anvilHM::g_time.deltaTime;
	if (m_fireTimer <= 0)
	{
		//Enemy shooot
		
		m_fireTimer = anvilHM::randomf(5);
		anvilHM::Transform transform = m_transform;
		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(anvilHM::Model{ "EnemyBullet.txt" }, transform, 0.5f);
		
		bullet->GetTag() = "enemy";
		m_scene->Add(std::move(bullet));
	}

	// set rotation towards player
	player* Player = m_scene->anvilHM::Scene::GetActor<player>();
	if (Player)
	{
		anvilHM::Vector2 direction = Player->m_transform.position - m_transform.position;
		m_transform.rotation = direction.GetAngle();
	}

	// calculate velocity 
	anvilHM::Vector2 direction{ 1, 0 };
	direction = anvilHM::Vector2::Rotate(direction, m_transform.rotation);
	anvilHM::Vector2 velocity = direction * m_speed * anvilHM::g_time.deltaTime;
	// move
	m_transform.position += velocity;

	if (m_transform.position.x > anvilHM::g_renderer.GetWidth()) m_transform.position.x = 0;
	if (m_transform.position.x < 0) m_transform.position.x = (float)anvilHM::g_renderer.GetWidth();
	if (m_transform.position.y > anvilHM::g_renderer.GetHeight()) m_transform.position.y = 0;
	if (m_transform.position.y < 0) m_transform.position.y = (float)anvilHM::g_renderer.GetHeight();

}