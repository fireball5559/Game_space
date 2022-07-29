#pragma once
#include "../GameObject.h"
#include "../Renderer/Model.h"
#include "../Math/Transform.h"
//#include "Scene.h"

namespace anvilHM 
{
	class Scene;
	class Actor : public GameObject 
	{
	public:
		Actor() = default;
		Actor(const Model& model,const Transform& transform) :
			GameObject{ transform },
			m_model{ model }{};

		virtual void Update() override {};
		virtual void Draw(Renderer& render);
		
		virtual void OnCollision(Actor* other) {};
		float GetRadius() { return m_model.GetRadius() * m_transform.scale; }
		std::string& GetTag() { return m_tag; }//we  change the copy of it so we ahve to refrence it
		
		friend class Scene;

	protected:	
		//Tag time
		std::string m_tag;

		bool m_destroy = false;

		//physics
		Vector2 m_velocity;
		float m_damping =1;

		Model m_model;
		Scene* m_scene = nullptr;
	};
}