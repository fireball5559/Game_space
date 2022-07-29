#pragma once
#include<cstdint>
#include<vector>
#include<array>
#include "../Math/Vector2.h"

namespace anvilHM 
{
	class InputSystem
	{
	public:
		InputSystem() = default;
		~InputSystem() = default;

		void Initialize();
		void Shutdown();
		
		void Update(); 
		enum class KeyState {
			Idle,
			Pressed,
			Held,
			Release
		};

		KeyState GetKeyState(uint32_t key);
		bool GetKeyDown(uint32_t key) { return m_keyboardState[key]; }
		bool GetPreviousKeyDown(uint32_t key) { return m_prevKeyboardState[key]; }

		const Vector2& GetMousePosition() const { return m_mousePosition; }

		KeyState GetButtonState(uint32_t button);
		bool GetButtonDown(uint32_t button) { return m_mouseButtonState[button]; }
		bool GetPreviousButtonDown(uint32_t button) {
			return m_prevMouseButtonState[button];
		}
	private:
		int m_numKeys;
		std::vector<uint8_t>m_keyboardState;
		std::vector<uint8_t>m_prevKeyboardState;

		Vector2 m_mousePosition;
		std::array<uint8_t, 3> m_mouseButtonState;
		std::array<uint8_t, 3> m_prevMouseButtonState;

	};//semicolon at the end to give less errors moving forward
	extern const uint32_t key_space;
	extern const uint32_t key_up;
	extern const uint32_t key_down;
	extern const uint32_t key_left;
	extern const uint32_t key_right;
	extern const uint32_t key_escape;
	extern const uint32_t key_R;
	extern const uint32_t button_left;
	extern const uint32_t button_middle;	
	extern const uint32_t button_right;


}
