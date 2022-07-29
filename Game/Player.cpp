#include "Player.h"
#include "Engine.h"
#include "Bullet.h"

void player::Update()
{
	//input rotate left/right
	
	if (anvilHM::g_input.GetKeyState(anvilHM::key_left) == anvilHM::InputSystem::KeyState::Held)
	{
		m_transform.rotation -= math::HalfPi*anvilHM::g_time.deltaTime +.05;
	}
	if (anvilHM::g_input.GetKeyState(anvilHM::key_right) ==anvilHM::InputSystem::KeyState::Held)
	{
		m_transform.rotation += math::HalfPi * anvilHM::g_time.deltaTime + .05;
	}
	//speed set
	m_speed = 0;
	if (anvilHM::g_input.GetKeyState(anvilHM::key_up) == anvilHM::InputSystem::KeyState::Held)
	{
		m_speed = m_maxspeed;
	}
	// calculate force 
	anvilHM::Vector2 direction{ 1, 0 };
	direction = anvilHM::Vector2::Rotate(direction, m_transform.rotation);
	anvilHM::Vector2 force = direction * m_speed * anvilHM::g_time.deltaTime;
	// apply force to velocity
	m_velocity += force;
	// apply drag
	m_velocity *= 1.0f / (1.0f + m_damping * anvilHM::g_time.deltaTime);

	// move
	m_transform.position += m_velocity*anvilHM::g_time.deltaTime;

	// wrap
	if (m_transform.position.x > anvilHM::g_renderer.GetWidth()) m_transform.position.x = 0;
	if (m_transform.position.x < 0) m_transform.position.x = (float)anvilHM::g_renderer.GetWidth();
	if (m_transform.position.y > anvilHM::g_renderer.GetHeight()) m_transform.position.y = 0;
	if (m_transform.position.y < 0) m_transform.position.y = (float)anvilHM::g_renderer.GetHeight();


	// fire bullet
	//Big damage bullet
	m_fireRate2 -= anvilHM::g_time.deltaTime;
	if (m_fireRate2<=0) {
		if (anvilHM::g_input.GetKeyState(anvilHM::key_R) == anvilHM::InputSystem::KeyState::Held)
		{
			m_fireRate2 = 1;

			// fire
			anvilHM::Transform transform = m_transform;
			transform.scale = 4;
			std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(anvilHM::Model{ "BigBullet.txt" }, transform, 6);
			bullet->GetTag() = "player";
			m_scene->Add(std::move(bullet));
			anvilHM::g_audio.PlayAudio("Laser");
		}
	}
	//small machine gun
	m_fireRate -= anvilHM::g_time.deltaTime;
	if (m_fireRate <= 0) {
		if (anvilHM::g_input.GetKeyState(anvilHM::key_space) == anvilHM::InputSystem::KeyState::Held)
		{
			m_fireRate = 0.3;

			// fire
			anvilHM::Transform transform = m_transform;
			std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(anvilHM::Model{ "Bullet.txt" }, transform, 2);
			bullet->GetTag() = "player";
			m_scene->Add(std::move(bullet));
			anvilHM::g_audio.PlayAudio("Laser");
			//this is where laser play audio would go

		}
	}
}

void player::OnCollision(Actor* other)
{
	if (dynamic_cast<Bullet*>(other) && other->GetTag() == "enemy")
	{
		m_health -=  dynamic_cast<Bullet*>(other)->GetDamage();
		m_scene->GetGame()->adjustHealth(dynamic_cast<Bullet*>(other)->GetDamage());
		if(m_health <= 0)m_destroy = true;
	}
}
