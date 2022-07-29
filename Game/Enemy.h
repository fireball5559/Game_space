#pragma once
#include "Framwork/Actor.h"
class Enemy :public anvilHM::Actor
{
public:
	Enemy() = default;
	Enemy(const anvilHM::Model& model, const anvilHM::Transform& transform, float health = 1) :
		Actor{ model, transform }, m_health{ health } {
		Initialize();
	}
	void OnCollision(Actor* other) override;
	void Initialize();
	void Update() override;

private:
	float m_health = 1;
	float m_speed = 50;
	float m_fireTimer = 0;
};