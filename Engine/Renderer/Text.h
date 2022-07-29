#pragma once
#include <string>

struct SDL_Texture;//struct to forward

namespace anvilHM
{
	
	class Renderer;
	class Font;
	struct Color;
	struct Vector2;

	class Text
	{
	public:
	Text() = default; //<- more errors when enabled
	//~Text()= default;
	Text(Font* font) : m_font(font) {}
	~Text();

	void Create(Renderer& renderer, const std::string& text, const Color& color);
	void Draw(Renderer& renderer, const Vector2& position);
	
	friend class Font;

	private:
	 Font* m_font = nullptr;
	 SDL_Texture* m_texture =nullptr;
	};
}

