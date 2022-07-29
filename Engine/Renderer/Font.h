#pragma once
#include <string>

//TTF_Font?
struct _TTF_Font;

namespace anvilHM 
{
	class Font 
	{
	
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		void Load(const std::string& filename, int fontSize);
		
		friend class Text;

	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}