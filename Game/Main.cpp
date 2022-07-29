#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "Core/Memory.h"
#include "Core/File.h"
#include "SpaceShooter.h"
#include <iostream>
#include <vector>
#include <cinttypes>

//#include "Core/Time.h"
//#include <Windows.h>
//
//#include <sysinfoapi.h>
//#define WIN32_LEAN_AND_MEAN //broken


using namespace std;

int main()
{
//initialize important items
	anvilHM::InitializeMemory();

	anvilHM::SetFilePath("../Assets");
//Initialize System
	anvilHM::g_renderer.Initialize();
	anvilHM::g_input.Initialize();
	anvilHM::g_audio.Initialize();
//create window
	anvilHM::g_renderer.CreateWindow("Good ol' space", 800, 600);
	anvilHM::g_renderer.SetClearColor(anvilHM::Color{ 50, 50, 50, 255 });
//Create Game
	SpaceShooter game;
	game.Initialize();
	anvilHM::g_audio.PlayAudio("Music",true);
	bool quit = false;
	while (!quit)
	{
	// update (engine)/Audio
		anvilHM::g_time.Tick();
		anvilHM::g_input.Update();
		anvilHM::g_audio.Update();
	//check for exit
		if (anvilHM::g_input.GetKeyDown(anvilHM::key_escape)) quit = true;
	//Update
		game.Update();

	//Render
		anvilHM::g_renderer.BeginFrame();
		game.Draw(anvilHM::g_renderer);
		anvilHM::g_renderer.EndFrame();

	}
	//destroy game and ont, than the things below
	anvilHM::g_renderer.Shutdown();
	anvilHM::g_audio.Shutdown();
}
