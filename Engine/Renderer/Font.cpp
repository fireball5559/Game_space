#include "Font.h"
#include <SDL_ttf.h>

namespace anvilHM
{
	Font::Font(const std::string& filename, int fontSize)
	{
		// !! call Load() function below passing filename and fontSize
		Load(filename, fontSize);
	}

	Font::~Font()
	{
		// !! if m_ttfFont not null, close font (TTF_CloseFont)
		if (m_ttfFont != NULL) 
		{
			TTF_CloseFont(m_ttfFont);
			m_ttfFont = nullptr;
		}
	}

	void Font::Load(const std::string& filename, int fontSize)
	{
		//Note -Opens the File, but has to be classafied as File and not .ttf, Or thats what works i guess
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
 	}
}