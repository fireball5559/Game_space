#include "Actor.h"

namespace anvilHM {
	
	void Actor::Draw(Renderer& render)
	{
		m_model.Draw(render, m_transform.position, m_transform.rotation, m_transform.scale);
	}
}