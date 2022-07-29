#include <Framwork/Actor.h>

#pragma once
class player :public anvilHM::Actor 
{
public:
	player() = default;
	player(const anvilHM::Model model, const anvilHM::Transform& tranform) :
		Actor{ model, tranform } {};
	void Update() override;
	void OnCollision(Actor* other)override;
	float GetHealth() { return m_health; };
private:
	float m_health{ 10.0f };//different initialization just be consistent
	float m_maxspeed = {200.0f};
	float m_speed = {0.0f};
	float m_fireRate = { 0.3f };
	float m_fireRate2 = { 1.0f };

};
