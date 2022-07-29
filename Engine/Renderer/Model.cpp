#include "Model.h"
#include "../Core/File.h"
#include <sstream>
#include <iostream>
namespace anvilHM
{
	Model::Model(const std::string filename)
	{
		Load(filename);
		m_radius = CalculateRadius();
	}
	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, float scale)
	{

		// draw model
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			anvilHM::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			anvilHM::Vector2 p2 = Vector2::Rotate((m_points[i + 1] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	void Model::Load(const std::string& fileName)
	{
		std::string buffer;
		anvilHM::ReadFile(fileName, buffer);
		// read color
		std::istringstream stream(buffer);
		stream >> m_color;
		
		std::string line;
		std::getline(stream, line);
		//get number of points
		size_t numPoints = std::stoi(line);

		//read model points 
		for (size_t i = 0; i < numPoints; i++) 
		{
			Vector2 point;

			stream >> point;
			m_points.push_back(point);
		}

		//std::cout << line << std::endl; // prints out the number of points/ not the points
	}

	float Model::CalculateRadius()
	{
		float radius = 0;
		//find largest Length
		for (auto point : m_points)//auto so nice, it automatically tells it what to be, so it is a vector2
		{
			if (point.Length() > radius)radius = point.Length();
		}


		return radius;
	}

}
