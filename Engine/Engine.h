#pragma once
#include "Math/MathUtils.h"
#include "Math/Random.h"
#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"
#include "Framwork/Scene.h"

#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Framwork/Scene.h"
#include "Framwork/Game.h"

#include <iostream>
#include <vector>
#include <memory>


namespace anvilHM 
{
	extern Renderer g_renderer;
	extern InputSystem g_input;
	extern Time g_time;
	extern AudioSystem g_audio;
}