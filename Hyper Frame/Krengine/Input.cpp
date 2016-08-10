#include "Input.hpp"
#include <SDL2/SDL.h>

namespace Krengine
{
	bool Input::VK_0 = false;
	bool Input::VK_1 = false;
	bool Input::VK_2 = false;
	bool Input::VK_3 = false;
	bool Input::VK_4 = false;
	bool Input::VK_5 = false;
	bool Input::VK_6 = false;
	bool Input::VK_7 = false;
	bool Input::VK_8 = false;
	bool Input::VK_9 = false;
	bool Input::VK_A = false;
	bool Input::VK_QUOTE = false;
	bool Input::VK_B = false;
	bool Input::VK_BACKSLASH = false;
	bool Input::VK_BACKSPACE = false;
	bool Input::VK_C = false;
	bool Input::VK_CAPSLOCK = false;
	bool Input::VK_COMMA = false;
	bool Input::VK_D = false;
	bool Input::VK_DELETE = false;
	bool Input::VK_DOWN = false;
	bool Input::VK_E = false;
	bool Input::VK_END = false;
	bool Input::VK_EQUALS = false;
	bool Input::VK_ESCAPE = false;
	bool Input::VK_F = false;
	bool Input::VK_F1 = false;
	bool Input::VK_F10 = false;
	bool Input::VK_F11 = false;
	bool Input::VK_F12 = false;
	bool Input::VK_F2 = false;
	bool Input::VK_F3 = false;
	bool Input::VK_F4 = false;
	bool Input::VK_F5 = false;
	bool Input::VK_F6 = false;
	bool Input::VK_F7 = false;
	bool Input::VK_F8 = false;
	bool Input::VK_F9 = false;
	bool Input::VK_G = false;
	bool Input::VK_BACKQUOTE = false;
	bool Input::VK_H = false;
	bool Input::VK_HOME = false;
	bool Input::VK_I = false;
	bool Input::VK_INSERT = false;
	bool Input::VK_J = false;
	bool Input::VK_K = false;
	bool Input::VK_KP_0 = false;
	bool Input::VK_KP_1 = false;
	bool Input::VK_KP_2 = false;
	bool Input::VK_KP_3 = false;
	bool Input::VK_KP_4 = false;
	bool Input::VK_KP_5 = false;
	bool Input::VK_KP_6 = false;
	bool Input::VK_KP_7 = false;
	bool Input::VK_KP_8 = false;
	bool Input::VK_KP_9 = false;
	bool Input::VK_KP_DIVIDE = false;
	bool Input::VK_KP_ENTER = false;
	bool Input::VK_KP_MINUS = false;
	bool Input::VK_KP_MULTIPLY = false;
	bool Input::VK_KP_PERIOD = false;
	bool Input::VK_KP_PLUS = false;
	bool Input::VK_L = false;
	bool Input::VK_LALT = false;
	bool Input::VK_LCTRL = false;
	bool Input::VK_LEFT = false;
	bool Input::VK_LEFTBRACKET = false;
	bool Input::VK_LGUI = false;
	bool Input::VK_LSHIFT = false;
	bool Input::VK_M = false;
	bool Input::VK_MINUS = false;
	bool Input::VK_N = false;
	bool Input::VK_NUMLOCKCLEAR = false;
	bool Input::VK_O = false;
	bool Input::VK_P = false;
	bool Input::VK_PAGEDOWN = false;
	bool Input::VK_PAGEUP = false;
	bool Input::VK_PAUSE = false;
	bool Input::VK_PERIOD = false;
	bool Input::VK_PRINTSCREEN = false;
	bool Input::VK_Q = false;
	bool Input::VK_R = false;
	bool Input::VK_RALT = false;
	bool Input::VK_RCTRL = false;
	bool Input::VK_RETURN = false;
	bool Input::VK_RGUI = false;
	bool Input::VK_RIGHT = false;
	bool Input::VK_RIGHTBRACKET = false;
	bool Input::VK_RSHIFT = false;
	bool Input::VK_S = false;
	bool Input::VK_SCROLLLOCK = false;
	bool Input::VK_SEMICOLON = false;
	bool Input::VK_SLASH = false;
	bool Input::VK_SPACE = false;
	bool Input::VK_T = false;
	bool Input::VK_TAB = false;
	bool Input::VK_U = false;
	bool Input::VK_UP = false;
	bool Input::VK_V = false;
	bool Input::VK_W = false;
	bool Input::VK_X = false;
	bool Input::VK_Y = false;
	bool Input::VK_Z = false;

	int Input::mouseX = 0;
	int Input::mouseY = 0;
	bool Input::mouse1 = false;
	bool Input::mouse2 = false;
	bool Input::mouse3 = false;
	bool Input::mouse4 = false;
	bool Input::mouse5 = false;
	int Input::mouseWheel = 0;

	bool Input::Update()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
						case SDLK_0:
							VK_0 = true;

							break;

						case SDLK_1:
							VK_1 = true;

							break;

						case SDLK_2:
							VK_2 = true;

							break;

						case SDLK_3:
							VK_3 = true;

							break;

						case SDLK_4:
							VK_4 = true;

							break;

						case SDLK_5:
							VK_5 = true;

							break;

						case SDLK_6:
							VK_6 = true;

							break;

						case SDLK_7:
							VK_7 = true;

							break;

						case SDLK_8:
							VK_8 = true;

							break;

						case SDLK_9:
							VK_9 = true;

							break;

						case SDLK_a:
							VK_A = true;

							break;

						case SDLK_QUOTE:
							VK_QUOTE = true;

							break;

						case SDLK_b:
							VK_B = true;

							break;

						case SDLK_BACKSLASH:
							VK_BACKSLASH = true;

							break;

						case SDLK_BACKSPACE:
							VK_BACKSPACE = true;

							break;

						case SDLK_c:
							VK_C = true;

							break;

						case SDLK_CAPSLOCK:
							VK_CAPSLOCK = true;

							break;

						case SDLK_COMMA:
							VK_COMMA = true;

							break;

						case SDLK_d:
							VK_D = true;

							break;

						case SDLK_DELETE:
							VK_DELETE = true;

							break;

						case SDLK_DOWN:
							VK_DOWN = true;

							break;

						case SDLK_e:
							VK_E = true;

							break;

						case SDLK_END:
							VK_END = true;

							break;

						case SDLK_EQUALS:
							VK_EQUALS = true;

							break;

						case SDLK_ESCAPE:
							VK_ESCAPE = true;

							break;

						case SDLK_f:
							VK_F = true;

							break;

						case SDLK_F1:
							VK_F1 = true;

							break;

						case SDLK_F10:
							VK_F10 = true;

							break;

						case SDLK_F11:
							VK_F11 = true;

							break;

						case SDLK_F12:
							VK_F12 = true;

							break;

						case SDLK_F2:
							VK_F2 = true;

							break;

						case SDLK_F3:
							VK_F3 = true;

							break;

						case SDLK_F4:
							VK_F4 = true;

							break;

						case SDLK_F5:
							VK_F5 = true;

							break;

						case SDLK_F6:
							VK_F6 = true;

							break;

						case SDLK_F7:
							VK_F7 = true;

							break;

						case SDLK_F8:
							VK_F8 = true;

							break;

						case SDLK_F9:
							VK_F9 = true;

							break;

						case SDLK_g:
							VK_G = true;

							break;

						case SDLK_BACKQUOTE:
							VK_BACKQUOTE = true;

							break;

						case SDLK_h:
							VK_H = true;

							break;

						case SDLK_HOME:
							VK_HOME = true;

							break;

						case SDLK_i:
							VK_I = true;

							break;

						case SDLK_INSERT:
							VK_INSERT = true;

							break;

						case SDLK_j:
							VK_J = true;

							break;

						case SDLK_k:
							VK_K = true;

							break;

						case SDLK_KP_0:
							VK_KP_0 = true;

							break;

						case SDLK_KP_1:
							VK_KP_1 = true;

							break;

						case SDLK_KP_2:
							VK_KP_2 = true;

							break;

						case SDLK_KP_3:
							VK_KP_3 = true;

							break;

						case SDLK_KP_4:
							VK_KP_4 = true;

							break;

						case SDLK_KP_5:
							VK_KP_5 = true;

							break;

						case SDLK_KP_6:
							VK_KP_6 = true;

							break;

						case SDLK_KP_7:
							VK_KP_7 = true;

							break;

						case SDLK_KP_8:
							VK_KP_8 = true;

							break;

						case SDLK_KP_9:
							VK_KP_9 = true;

							break;

						case SDLK_KP_DIVIDE:
							VK_KP_DIVIDE = true;

							break;

						case SDLK_KP_ENTER:
							VK_KP_ENTER = true;

							break;

						case SDLK_KP_MINUS:
							VK_KP_MINUS = true;

							break;

						case SDLK_KP_MULTIPLY:
							VK_KP_MULTIPLY = true;

							break;

						case SDLK_KP_PERIOD:
							VK_KP_PERIOD = true;

							break;

						case SDLK_KP_PLUS:
							VK_KP_PLUS = true;

							break;

						case SDLK_l:
							VK_L = true;

							break;

						case SDLK_LALT:
							VK_LALT = true;

							break;

						case SDLK_LCTRL:
							VK_LCTRL = true;

							break;

						case SDLK_LEFT:
							VK_LEFT = true;

							break;

						case SDLK_LEFTBRACKET:
							VK_LEFTBRACKET = true;

							break;

						case SDLK_LGUI:
							VK_LGUI = true;

							break;

						case SDLK_LSHIFT:
							VK_LSHIFT = true;

							break;

						case SDLK_m:
							VK_M = true;

							break;

						case SDLK_MINUS:
							VK_MINUS = true;

							break;

						case SDLK_n:
							VK_N = true;

							break;

						case SDLK_NUMLOCKCLEAR:
							VK_NUMLOCKCLEAR = true;

							break;

						case SDLK_o:
							VK_O = true;

							break;

						case SDLK_p:
							VK_P = true;

							break;

						case SDLK_PAGEDOWN:
							VK_PAGEDOWN = true;

							break;

						case SDLK_PAGEUP:
							VK_PAGEDOWN = true;

							break;

						case SDLK_PAUSE:
							VK_PAUSE = true;

							break;

						case SDLK_PERIOD:
							VK_PERIOD = true;

							break;

						case SDLK_PRINTSCREEN:
							VK_PRINTSCREEN = true;

							break;

						case SDLK_q:
							VK_Q = true;

							break;

						case SDLK_r:
							VK_R = true;

							break;

						case SDLK_RALT:
							VK_RALT = true;

							break;

						case SDLK_RCTRL:
							VK_RCTRL = true;

							break;

						case SDLK_RETURN:
							VK_RETURN = true;

							break;

						case SDLK_RGUI:
							VK_RGUI = true;

							break;

						case SDLK_RIGHT:
							VK_RIGHT = true;

							break;

						case SDLK_RIGHTBRACKET:
							VK_RIGHTBRACKET = true;

							break;

						case SDLK_RSHIFT:
							VK_RSHIFT = true;

							break;

						case SDLK_s:
							VK_S = true;

							break;

						case SDLK_SCROLLLOCK:
							VK_SCROLLLOCK = true;

							break;

						case SDLK_SEMICOLON:
							VK_SEMICOLON = true;

							break;

						case SDLK_SLASH:
							VK_SLASH = true;

							break;

						case SDLK_SPACE:
							VK_SPACE = true;

							break;

						case SDLK_t:
							VK_T = true;

							break;

						case SDLK_TAB:
							VK_TAB = true;

							break;

						case SDLK_u:
							VK_U = true;

							break;

						case SDLK_UP:
							VK_UP = true;

							break;

						case SDLK_v:
							VK_V = true;

							break;

						case SDLK_w:
							VK_W = true;

							break;

						case SDLK_x:
							VK_X = true;

							break;

						case SDLK_y:
							VK_Y = true;

							break;

						case SDLK_z:
							VK_Z = true;

							break;
					}

					break;

				case SDL_KEYUP:
					switch (event.key.keysym.sym)
					{
						case SDLK_0:
							VK_0 = false;

							break;

						case SDLK_1:
							VK_1 = false;

							break;

						case SDLK_2:
							VK_2 = false;

							break;

						case SDLK_3:
							VK_3 = false;

							break;

						case SDLK_4:
							VK_4 = false;

							break;

						case SDLK_5:
							VK_5 = false;

							break;

						case SDLK_6:
							VK_6 = false;

							break;

						case SDLK_7:
							VK_7 = false;

							break;

						case SDLK_8:
							VK_8 = false;

							break;

						case SDLK_9:
							VK_9 = false;

							break;

						case SDLK_a:
							VK_A = false;

							break;

						case SDLK_QUOTE:
							VK_QUOTE = false;

							break;

						case SDLK_b:
							VK_B = false;

							break;

						case SDLK_BACKSLASH:
							VK_BACKSLASH = false;

							break;

						case SDLK_BACKSPACE:
							VK_BACKSPACE = false;

							break;

						case SDLK_c:
							VK_C = false;

							break;

						case SDLK_CAPSLOCK:
							VK_CAPSLOCK = false;

							break;

						case SDLK_COMMA:
							VK_COMMA = false;

							break;

						case SDLK_d:
							VK_D = false;

							break;

						case SDLK_DELETE:
							VK_DELETE = false;

							break;

						case SDLK_DOWN:
							VK_DOWN = false;

							break;

						case SDLK_e:
							VK_E = false;

							break;

						case SDLK_END:
							VK_END = false;

							break;

						case SDLK_EQUALS:
							VK_EQUALS = false;

							break;

						case SDLK_ESCAPE:
							VK_ESCAPE = false;

							break;

						case SDLK_f:
							VK_F = false;

							break;

						case SDLK_F1:
							VK_F1 = false;

							break;

						case SDLK_F10:
							VK_F10 = false;

							break;

						case SDLK_F11:
							VK_F11 = false;

							break;

						case SDLK_F12:
							VK_F12 = false;

							break;

						case SDLK_F2:
							VK_F2 = false;

							break;

						case SDLK_F3:
							VK_F3 = false;

							break;

						case SDLK_F4:
							VK_F4 = false;

							break;

						case SDLK_F5:
							VK_F5 = false;

							break;

						case SDLK_F6:
							VK_F6 = false;

							break;

						case SDLK_F7:
							VK_F7 = false;

							break;

						case SDLK_F8:
							VK_F8 = false;

							break;

						case SDLK_F9:
							VK_F9 = false;

							break;

						case SDLK_g:
							VK_G = false;

							break;

						case SDLK_BACKQUOTE:
							VK_BACKQUOTE = false;

							break;

						case SDLK_h:
							VK_H = false;

							break;

						case SDLK_HOME:
							VK_HOME = false;

							break;

						case SDLK_i:
							VK_I = false;

							break;

						case SDLK_INSERT:
							VK_INSERT = false;

							break;

						case SDLK_j:
							VK_J = false;

							break;

						case SDLK_k:
							VK_K = false;

							break;

						case SDLK_KP_0:
							VK_KP_0 = false;

							break;

						case SDLK_KP_1:
							VK_KP_1 = false;

							break;

						case SDLK_KP_2:
							VK_KP_2 = false;

							break;

						case SDLK_KP_3:
							VK_KP_3 = false;

							break;

						case SDLK_KP_4:
							VK_KP_4 = false;

							break;

						case SDLK_KP_5:
							VK_KP_5 = false;

							break;

						case SDLK_KP_6:
							VK_KP_6 = false;

							break;

						case SDLK_KP_7:
							VK_KP_7 = false;

							break;

						case SDLK_KP_8:
							VK_KP_8 = false;

							break;

						case SDLK_KP_9:
							VK_KP_9 = false;

							break;

						case SDLK_KP_DIVIDE:
							VK_KP_DIVIDE = false;

							break;

						case SDLK_KP_ENTER:
							VK_KP_ENTER = false;

							break;

						case SDLK_KP_MINUS:
							VK_KP_MINUS = false;

							break;

						case SDLK_KP_MULTIPLY:
							VK_KP_MULTIPLY = false;

							break;

						case SDLK_KP_PERIOD:
							VK_KP_PERIOD = false;

							break;

						case SDLK_KP_PLUS:
							VK_KP_PLUS = false;

							break;

						case SDLK_l:
							VK_L = false;

							break;

						case SDLK_LALT:
							VK_LALT = false;

							break;

						case SDLK_LCTRL:
							VK_LCTRL = false;

							break;

						case SDLK_LEFT:
							VK_LEFT = false;

							break;

						case SDLK_LEFTBRACKET:
							VK_LEFTBRACKET = false;

							break;

						case SDLK_LGUI:
							VK_LGUI = false;

							break;

						case SDLK_LSHIFT:
							VK_LSHIFT = false;

							break;

						case SDLK_m:
							VK_M = false;

							break;

						case SDLK_MINUS:
							VK_MINUS = false;

							break;

						case SDLK_n:
							VK_N = false;

							break;

						case SDLK_NUMLOCKCLEAR:
							VK_NUMLOCKCLEAR = false;

							break;

						case SDLK_o:
							VK_O = false;

							break;

						case SDLK_p:
							VK_P = false;

							break;

						case SDLK_PAGEDOWN:
							VK_PAGEDOWN = false;

							break;

						case SDLK_PAGEUP:
							VK_PAGEDOWN = false;

							break;

						case SDLK_PAUSE:
							VK_PAUSE = false;

							break;

						case SDLK_PERIOD:
							VK_PERIOD = false;

							break;

						case SDLK_PRINTSCREEN:
							VK_PRINTSCREEN = false;

							break;

						case SDLK_q:
							VK_Q = false;

							break;

						case SDLK_r:
							VK_R = false;

							break;

						case SDLK_RALT:
							VK_RALT = false;

							break;

						case SDLK_RCTRL:
							VK_RCTRL = false;

							break;

						case SDLK_RETURN:
							VK_RETURN = false;

							break;

						case SDLK_RGUI:
							VK_RGUI = false;

							break;

						case SDLK_RIGHT:
							VK_RIGHT = false;

							break;

						case SDLK_RIGHTBRACKET:
							VK_RIGHTBRACKET = false;

							break;

						case SDLK_RSHIFT:
							VK_RSHIFT = false;

							break;

						case SDLK_s:
							VK_S = false;
							
							break;
							
						case SDLK_SCROLLLOCK:
							VK_SCROLLLOCK = false;
							
							break;
							
						case SDLK_SEMICOLON:
							VK_SEMICOLON = false;
							
							break;
							
						case SDLK_SLASH:
							VK_SLASH = false;
							
							break;
							
						case SDLK_SPACE:
							VK_SPACE = false;
							
							break;
							
						case SDLK_t:
							VK_T = false;
							
							break;
							
						case SDLK_TAB:
							VK_TAB = false;
							
							break;
							
						case SDLK_u:
							VK_U = false;
							
							break;
							
						case SDLK_UP:
							VK_UP = false;
							
							break;
							
						case SDLK_v:
							VK_V = false;
							
							break;
							
						case SDLK_w:
							VK_W = false;
							
							break;
							
						case SDLK_x:
							VK_X = false;
							
							break;
							
						case SDLK_y:
							VK_Y = false;
							
							break;
							
						case SDLK_z:
							VK_Z = false;
							
							break;
					}

					break;

				case SDL_MOUSEMOTION:
					mouseX = event.motion.x;
					mouseY = event.motion.y;

					break;

				case SDL_MOUSEBUTTONDOWN:
					switch (event.button.button)
					{
						case SDL_BUTTON_LEFT:
							mouse1 = true;

							break;

						case SDL_BUTTON_RIGHT:
							mouse2 = true;

							break;

						case SDL_BUTTON_MIDDLE:
							mouse3 = true;

							break;

						case SDL_BUTTON_X1:
							mouse4 = true;

							break;

						case SDL_BUTTON_X2:
							mouse5 = true;

							break;
					}

					break;

				case SDL_MOUSEBUTTONUP:
					switch (event.button.button)
					{
						case SDL_BUTTON_LEFT:
							mouse1 = false;

							break;

						case SDL_BUTTON_RIGHT:
							mouse2 = false;

							break;

						case SDL_BUTTON_MIDDLE:
							mouse3 = false;

							break;

						case SDL_BUTTON_X1:
							mouse4 = false;

							break;

						case SDL_BUTTON_X2:
							mouse5 = false;
							
							break;
					}

					break;

				case SDL_MOUSEWHEEL:
					mouseWheel = event.wheel.direction == SDL_MOUSEWHEEL_NORMAL ? -event.wheel.y : event.wheel.y;

					break;

				case SDL_QUIT:
					return false;
					
					break;
			}
		}

		return true;
	}

	bool Input::GetVK_0()
	{
		return VK_0;
	}

	bool Input::GetVK_1()
	{
		return VK_1;
	}

	bool Input::GetVK_2()
	{
		return VK_2;
	}

	bool Input::GetVK_3()
	{
		return VK_3;
	}

	bool Input::GetVK_4()
	{
		return VK_4;
	}

	bool Input::GetVK_5()
	{
		return VK_5;
	}

	bool Input::GetVK_6()
	{
		return VK_6;
	}

	bool Input::GetVK_7()
	{
		return VK_7;
	}

	bool Input::GetVK_8()
	{
		return VK_8;
	}

	bool Input::GetVK_9()
	{
		return VK_9;
	}

	bool Input::GetVK_A()
	{
		return VK_A;
	}

	bool Input::GetVK_QUOTE()
	{
		return VK_QUOTE;
	}

	bool Input::GetVK_B()
	{
		return VK_B;
	}

	bool Input::GetVK_BACKSLASH()
	{
		return VK_BACKSLASH;
	}

	bool Input::GetVK_BACKSPACE()
	{
		return VK_BACKSPACE;
	}

	bool Input::GetVK_C()
	{
		return VK_C;
	}

	bool Input::GetVK_CAPSLOCK()
	{
		return VK_CAPSLOCK;
	}

	bool Input::GetVK_COMMA()
	{
		return VK_COMMA;
	}

	bool Input::GetVK_D()
	{
		return VK_D;
	}

	bool Input::GetVK_DELETE()
	{
		return VK_DELETE;
	}

	bool Input::GetVK_DOWN()
	{
		return VK_DOWN;
	}

	bool Input::GetVK_E()
	{
		return VK_E;
	}

	bool Input::GetVK_END()
	{
		return VK_END;
	}

	bool Input::GetVK_EQUALS()
	{
		return VK_EQUALS;
	}

	bool Input::GetVK_ESCAPE()
	{
		return VK_ESCAPE;
	}

	bool Input::GetVK_F()
	{
		return VK_F;
	}

	bool Input::GetVK_F1()
	{
		return VK_F1;
	}

	bool Input::GetVK_F10()
	{
		return VK_F10;
	}

	bool Input::GetVK_F11()
	{
		return VK_F11;
	}

	bool Input::GetVK_F12()
	{
		return VK_F12;
	}

	bool Input::GetVK_F2()
	{
		return VK_F2;
	}

	bool Input::GetVK_F3()
	{
		return VK_F3;
	}

	bool Input::GetVK_F4()
	{
		return VK_F4;
	}

	bool Input::GetVK_F5()
	{
		return VK_F5;
	}

	bool Input::GetVK_F6()
	{
		return VK_F6;
	}

	bool Input::GetVK_F7()
	{
		return VK_F7;
	}

	bool Input::GetVK_F8()
	{
		return VK_F8;
	}

	bool Input::GetVK_F9()
	{
		return VK_F9;
	}

	bool Input::GetVK_G()
	{
		return VK_G;
	}

	bool Input::GetVK_BACKQUOTE()
	{
		return VK_BACKQUOTE;
	}

	bool Input::GetVK_H()
	{
		return VK_H;
	}

	bool Input::GetVK_HOME()
	{
		return VK_HOME;
	}

	bool Input::GetVK_I()
	{
		return VK_I;
	}

	bool Input::GetVK_INSERT()
	{
		return VK_INSERT;
	}

	bool Input::GetVK_J()
	{
		return VK_J;
	}

	bool Input::GetVK_K()
	{
		return VK_K;
	}

	bool Input::GetVK_KP_0()
	{
		return VK_KP_0;
	}

	bool Input::GetVK_KP_1()
	{
		return VK_KP_1;
	}

	bool Input::GetVK_KP_2()
	{
		return VK_KP_2;
	}

	bool Input::GetVK_KP_3()
	{
		return VK_KP_3;
	}

	bool Input::GetVK_KP_4()
	{
		return VK_KP_4;
	}

	bool Input::GetVK_KP_5()
	{
		return VK_KP_5;
	}

	bool Input::GetVK_KP_6()
	{
		return VK_KP_6;
	}

	bool Input::GetVK_KP_7()
	{
		return VK_KP_7;
	}

	bool Input::GetVK_KP_8()
	{
		return VK_KP_8;
	}

	bool Input::GetVK_KP_9()
	{
		return VK_KP_9;
	}

	bool Input::GetVK_KP_DIVIDE()
	{
		return VK_KP_DIVIDE;
	}

	bool Input::GetVK_KP_ENTER()
	{
		return VK_KP_ENTER;
	}

	bool Input::GetVK_KP_MINUS()
	{
		return VK_KP_MINUS;
	}

	bool Input::GetVK_KP_MULTIPLY()
	{
		return VK_KP_MULTIPLY;
	}

	bool Input::GetVK_KP_PERIOD()
	{
		return VK_KP_PERIOD;
	}

	bool Input::GetVK_KP_PLUS()
	{
		return VK_KP_PLUS;
	}

	bool Input::GetVK_L()
	{
		return VK_L;
	}

	bool Input::GetVK_LALT()
	{
		return VK_LALT;
	}

	bool Input::GetVK_LCTRL()
	{
		return VK_LCTRL;
	}

	bool Input::GetVK_LEFT()
	{
		return VK_LEFT;
	}

	bool Input::GetVK_LEFTBRACKET()
	{
		return VK_LEFTBRACKET;
	}

	bool Input::GetVK_LGUI()
	{
		return VK_LGUI;
	}

	bool Input::GetVK_LSHIFT()
	{
		return VK_LSHIFT;
	}

	bool Input::GetVK_M()
	{
		return VK_M;
	}

	bool Input::GetVK_MINUS()
	{
		return VK_MINUS;
	}

	bool Input::GetVK_N()
	{
		return VK_N;
	}

	bool Input::GetVK_NUMLOCKCLEAR()
	{
		return VK_NUMLOCKCLEAR;
	}

	bool Input::GetVK_O()
	{
		return VK_O;
	}

	bool Input::GetVK_P()
	{
		return VK_P;
	}

	bool Input::GetVK_PAGEDOWN()
	{
		return VK_PAGEDOWN;
	}

	bool Input::GetVK_PAGEUP()
	{
		return VK_PAGEUP;
	}

	bool Input::GetVK_PAUSE()
	{
		return VK_PAUSE;
	}

	bool Input::GetVK_PERIOD()
	{
		return VK_PERIOD;
	}

	bool Input::GetVK_PRINTSCREEN()
	{
		return VK_PRINTSCREEN;
	}

	bool Input::GetVK_Q()
	{
		return VK_Q;
	}

	bool Input::GetVK_R()
	{
		return VK_R;
	}

	bool Input::GetVK_RALT()
	{
		return VK_RALT;
	}

	bool Input::GetVK_RCTRL()
	{
		return VK_RCTRL;
	}

	bool Input::GetVK_RETURN()
	{
		return VK_RETURN;
	}

	bool Input::GetVK_RGUI()
	{
		return VK_RGUI;
	}

	bool Input::GetVK_RIGHT()
	{
		return VK_RIGHT;
	}

	bool Input::GetVK_RIGHTBRACKET()
	{
		return VK_RIGHTBRACKET;
	}

	bool Input::GetVK_RSHIFT()
	{
		return VK_RSHIFT;
	}

	bool Input::GetVK_S()
	{
		return VK_S;
	}

	bool Input::GetVK_SCROLLLOCK()
	{
		return VK_SCROLLLOCK;
	}
	
	bool Input::GetVK_SEMICOLON()
	{
		return VK_SEMICOLON;
	}
	
	bool Input::GetVK_SLASH()
	{
		return VK_SLASH;
	}
	
	bool Input::GetVK_SPACE()
	{
		return VK_SPACE;
	}
	
	bool Input::GetVK_T()
	{
		return VK_T;
	}
	
	bool Input::GetVK_TAB()
	{
		return VK_TAB;
	}
	
	bool Input::GetVK_U()
	{
		return VK_U;
	}
	
	bool Input::GetVK_UP()
	{
		return VK_UP;
	}
	
	bool Input::GetVK_V()
	{
		return VK_V;
	}
	
	bool Input::GetVK_W()
	{
		return VK_W;
	}
	
	bool Input::GetVK_X()
	{
		return VK_X;
	}
	
	bool Input::GetVK_Y()
	{
		return VK_Y;
	}
	
	bool Input::GetVK_Z()
	{
		return VK_Z;
	}

	int Input::GetMouseX()
	{
		return mouseX;
	}

	int Input::GetMouseY()
	{
		return mouseY;
	}

	bool Input::GetMouse1()
	{
		return mouse1;
	}

	bool Input::GetMouse2()
	{
		return mouse2;
	}

	bool Input::GetMouse3()
	{
		return mouse3;
	}

	bool Input::GetMouse4()
	{
		return mouse4;
	}

	bool Input::GetMouse5()
	{
		return mouse5;
	}

	int Input::GetMouseWheel()
	{
		return mouseWheel;
	}
}
