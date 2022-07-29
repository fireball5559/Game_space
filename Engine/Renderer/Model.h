#pragma once
#include "Renderer.h"
#include <vector>
#include <string>
namespace anvilHM
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<anvilHM::Vector2>& points, const anvilHM::Color& color) :
			m_points{ points },
			m_color{ color }{}
		Model(const std::string filename);
		void Draw(Renderer& renderer, const Vector2& position, float angle, float scale = 1);
		void Load(const std::string& fileName);
		float CalculateRadius();
		float GetRadius() { return m_radius; }
	private:
		// Color/Points
		anvilHM::Color m_color{0,0,0,0};
		std::vector<anvilHM::Vector2> m_points;
		float m_radius= 0;

	};
}
