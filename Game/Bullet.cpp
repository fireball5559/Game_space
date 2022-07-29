#include "Bullet.h"
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
void Bullet::Update()
{
	//
	m_lifespan -= anvilHM::g_time.deltaTime;
	if (m_lifespan <= 0) m_destroy = true;

	// calculate velocity 
	anvilHM::Vector2 direction{ 1, 0 };
	direction = anvilHM::Vector2::Rotate(direction, m_transform.rotation);
	anvilHM::Vector2 velocity = direction * m_speed * anvilHM::g_time.deltaTime;
	// move
	m_transform.position += velocity;

	// wrap
	if (m_transform.position.x > anvilHM::g_renderer.GetWidth()) m_transform.position.x = 0;
	if (m_transform.position.x < 0) m_transform.position.x = (float)anvilHM::g_renderer.GetWidth();
	if (m_transform.position.y > anvilHM::g_renderer.GetHeight()) m_transform.position.y = 0;
	if (m_transform.position.y < 0) m_transform.position.y = (float)anvilHM::g_renderer.GetHeight();
}

void Bullet::OnCollision(Actor* other)
{
	if (dynamic_cast<player*>(other) && GetTag() !="player")
	{
		m_destroy = true;
	}if (dynamic_cast<Enemy*>(other) && GetTag() != "enemy")//what we could do is give them two tags, one checks for bullet and other checks for actor
	{
		m_destroy = true;
	}

}
