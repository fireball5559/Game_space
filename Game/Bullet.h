#pragma once
#include "Framwork/Actor.h"
class Bullet : public anvilHM::Actor
{
public:
	Bullet() = default;
	Bullet(const anvilHM::Model& model, const anvilHM::Transform& transform, float damage = 1.0f) ://default perameter incase not passed in: damage= 1
		Actor{ model, transform }, m_damage{damage} {}

	void Update() override;
	void OnCollision(Actor* other) override;
	float GetDamage() { return m_damage; };

private:
	float m_damage = 1;
	float m_speed = 500;
	float m_lifespan = 1;
};