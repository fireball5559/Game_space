#pragma once
#include <cstdint>

namespace anvilHM
{
	//typedef unsigned char u8_t;
	//using u8_t = unsigned char;

	struct Color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;

		friend std::istream& operator >> (std::istream& stream, Color& color);
	};
	inline std::istream& operator >> (std::istream& stream, Color& c)
	{
		std::string line;
		std::getline(stream, line);
		std::string str;

		// { ##, ##, ## }

		//Getting the Red Color
		line = line.substr(line.find("{") + 1);
		str = line.substr(0, line.find(","));
		c.r = (uint8_t) (std::stof(str) *255);

		//Getting te Green color
		line = line.substr(line.find(",") + 1);
		str = line.substr(0, line.find(","));
		c.g = (uint8_t)(std::stof(str) * 255);

		//Getting the Blue color
		line = line.substr(line.find(",") + 1);
		str = line.substr(0, line.find("}"));
		c.b = (uint8_t)(std::stof(str) * 255);
		
		//setting the a
		c.a = 255;
		return stream;

	}
}
