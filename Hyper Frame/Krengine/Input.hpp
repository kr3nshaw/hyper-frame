#ifndef Input_hpp
#define Input_hpp

namespace Krengine
{
	/// <summary>Represents the input devices.</summary>
	class Input
	{
		public:
			/// <summary>Polls the input devices.</summary>
			/// <returns>Specifies whether the window has been closed or not.</returns>
			static bool Update();

			/// <summary>Gets a value indicating whether the 0 key is currently down or not.</summary>
			static bool GetVK_0();

			/// <summary>Gets a value indicating whether the 1 key is currently down or not.</summary>
			static bool GetVK_1();

			/// <summary>Gets a value indicating whether the 2 key is currently down or not.</summary>
			static bool GetVK_2();

			/// <summary>Gets a value indicating whether the 3 key is currently down or not.</summary>
			static bool GetVK_3();

			/// <summary>Gets a value indicating whether the 4 key is currently down or not.</summary>
			static bool GetVK_4();

			/// <summary>Gets a value indicating whether the 5 key is currently down or not.</summary>
			static bool GetVK_5();

			/// <summary>Gets a value indicating whether the 6 key is currently down or not.</summary>
			static bool GetVK_6();

			/// <summary>Gets a value indicating whether the 7 key is currently down or not.</summary>
			static bool GetVK_7();

			/// <summary>Gets a value indicating whether the 8 key is currently down or not.</summary>
			static bool GetVK_8();

			/// <summary>Gets a value indicating whether the 9 key is currently down or not.</summary>
			static bool GetVK_9();

			/// <summary>Gets a value indicating whether the A key is currently down or not.</summary>
			static bool GetVK_A();

			/// <summary>Gets a value indicating whether the QUOTE key is currently down or not.</summary>
			static bool GetVK_QUOTE();

			/// <summary>Gets a value indicating whether the B key is currently down or not.</summary>
			static bool GetVK_B();

			/// <summary>Gets a value indicating whether the BACKSLASH key is currently down or not.</summary>
			static bool GetVK_BACKSLASH();

			/// <summary>Gets a value indicating whether the BACKSPACE key is currently down or not.</summary>
			static bool GetVK_BACKSPACE();

			/// <summary>Gets a value indicating whether the C key is currently down or not.</summary>
			static bool GetVK_C();

			/// <summary>Gets a value indicating whether the CAPSLOCK key is currently down or not.</summary>
			static bool GetVK_CAPSLOCK();

			/// <summary>Gets a value indicating whether the COMMA key is currently down or not.</summary>
			static bool GetVK_COMMA();

			/// <summary>Gets a value indicating whether the D key is currently down or not.</summary>
			static bool GetVK_D();

			/// <summary>Gets a value indicating whether the DELETE key is currently down or not.</summary>
			static bool GetVK_DELETE();

			/// <summary>Gets a value indicating whether the DOWN key is currently down or not.</summary>
			static bool GetVK_DOWN();

			/// <summary>Gets a value indicating whether the E key is currently down or not.</summary>
			static bool GetVK_E();

			/// <summary>Gets a value indicating whether the END key is currently down or not.</summary>
			static bool GetVK_END();

			/// <summary>Gets a value indicating whether the EQUALS key is currently down or not.</summary>
			static bool GetVK_EQUALS();

			/// <summary>Gets a value indicating whether the ESCAPE key is currently down or not.</summary>
			static bool GetVK_ESCAPE();

			/// <summary>Gets a value indicating whether the F key is currently down or not.</summary>
			static bool GetVK_F();

			/// <summary>Gets a value indicating whether the F1 key is currently down or not.</summary>
			static bool GetVK_F1();

			/// <summary>Gets a value indicating whether the F10 key is currently down or not.</summary>
			static bool GetVK_F10();

			/// <summary>Gets a value indicating whether the F11 key is currently down or not.</summary>
			static bool GetVK_F11();

			/// <summary>Gets a value indicating whether the F12 key is currently down or not.</summary>
			static bool GetVK_F12();

			/// <summary>Gets a value indicating whether the F2 key is currently down or not.</summary>
			static bool GetVK_F2();

			/// <summary>Gets a value indicating whether the F3 key is currently down or not.</summary>
			static bool GetVK_F3();

			/// <summary>Gets a value indicating whether the F4 key is currently down or not.</summary>
			static bool GetVK_F4();

			/// <summary>Gets a value indicating whether the F5 key is currently down or not.</summary>
			static bool GetVK_F5();

			/// <summary>Gets a value indicating whether the F6 key is currently down or not.</summary>
			static bool GetVK_F6();

			/// <summary>Gets a value indicating whether the F7 key is currently down or not.</summary>
			static bool GetVK_F7();

			/// <summary>Gets a value indicating whether the F8 key is currently down or not.</summary>
			static bool GetVK_F8();

			/// <summary>Gets a value indicating whether the F9 key is currently down or not.</summary>
			static bool GetVK_F9();

			/// <summary>Gets a value indicating whether the G key is currently down or not.</summary>
			static bool GetVK_G();

			/// <summary>Gets a value indicating whether the BACKQUOTE key is currently down or not.</summary>
			static bool GetVK_BACKQUOTE();

			/// <summary>Gets a value indicating whether the H key is currently down or not.</summary>
			static bool GetVK_H();

			/// <summary>Gets a value indicating whether the HOME key is currently down or not.</summary>
			static bool GetVK_HOME();

			/// <summary>Gets a value indicating whether the I key is currently down or not.</summary>
			static bool GetVK_I();

			/// <summary>Gets a value indicating whether the INSERT key is currently down or not.</summary>
			static bool GetVK_INSERT();

			/// <summary>Gets a value indicating whether the J key is currently down or not.</summary>
			static bool GetVK_J();

			/// <summary>Gets a value indicating whether the K key is currently down or not.</summary>
			static bool GetVK_K();

			/// <summary>Gets a value indicating whether the KP_0 key is currently down or not.</summary>
			static bool GetVK_KP_0();

			/// <summary>Gets a value indicating whether the KP_1 key is currently down or not.</summary>
			static bool GetVK_KP_1();

			/// <summary>Gets a value indicating whether the KP_2 key is currently down or not.</summary>
			static bool GetVK_KP_2();

			/// <summary>Gets a value indicating whether the KP_3 key is currently down or not.</summary>
			static bool GetVK_KP_3();

			/// <summary>Gets a value indicating whether the KP_4 key is currently down or not.</summary>
			static bool GetVK_KP_4();

			/// <summary>Gets a value indicating whether the KP_5 key is currently down or not.</summary>
			static bool GetVK_KP_5();

			/// <summary>Gets a value indicating whether the KP_6 key is currently down or not.</summary>
			static bool GetVK_KP_6();

			/// <summary>Gets a value indicating whether the KP_7 key is currently down or not.</summary>
			static bool GetVK_KP_7();

			/// <summary>Gets a value indicating whether the KP_8 key is currently down or not.</summary>
			static bool GetVK_KP_8();

			/// <summary>Gets a value indicating whether the KP_9 key is currently down or not.</summary>
			static bool GetVK_KP_9();

			/// <summary>Gets a value indicating whether the KP_DIVIDE key is currently down or not.</summary>
			static bool GetVK_KP_DIVIDE();

			/// <summary>Gets a value indicating whether the KP_ENTER key is currently down or not.</summary>
			static bool GetVK_KP_ENTER();

			/// <summary>Gets a value indicating whether the KP_MINUS key is currently down or not.</summary>
			static bool GetVK_KP_MINUS();

			/// <summary>Gets a value indicating whether the KP_MULTIPLY key is currently down or not.</summary>
			static bool GetVK_KP_MULTIPLY();

			/// <summary>Gets a value indicating whether the KP_PERIOD key is currently down or not.</summary>
			static bool GetVK_KP_PERIOD();

			/// <summary>Gets a value indicating whether the KP_PLUS key is currently down or not.</summary>
			static bool GetVK_KP_PLUS();

			/// <summary>Gets a value indicating whether the L key is currently down or not.</summary>
			static bool GetVK_L();

			/// <summary>Gets a value indicating whether the LALT key is currently down or not.</summary>
			static bool GetVK_LALT();

			/// <summary>Gets a value indicating whether the LCTRL key is currently down or not.</summary>
			static bool GetVK_LCTRL();

			/// <summary>Gets a value indicating whether the LEFT key is currently down or not.</summary>
			static bool GetVK_LEFT();

			/// <summary>Gets a value indicating whether the LEFTBRACKET key is currently down or not.</summary>
			static bool GetVK_LEFTBRACKET();

			/// <summary>Gets a value indicating whether the LGUI key is currently down or not.</summary>
			static bool GetVK_LGUI();

			/// <summary>Gets a value indicating whether the LSHIFT key is currently down or not.</summary>
			static bool GetVK_LSHIFT();

			/// <summary>Gets a value indicating whether the M key is currently down or not.</summary>
			static bool GetVK_M();

			/// <summary>Gets a value indicating whether the MINUS key is currently down or not.</summary>
			static bool GetVK_MINUS();

			/// <summary>Gets a value indicating whether the N key is currently down or not.</summary>
			static bool GetVK_N();

			/// <summary>Gets a value indicating whether the NUMLOCKCLEAR key is currently down or not.</summary>
			static bool GetVK_NUMLOCKCLEAR();

			/// <summary>Gets a value indicating whether the O key is currently down or not.</summary>
			static bool GetVK_O();

			/// <summary>Gets a value indicating whether the P key is currently down or not.</summary>
			static bool GetVK_P();

			/// <summary>Gets a value indicating whether the PAGEDOWN key is currently down or not.</summary>
			static bool GetVK_PAGEDOWN();

			/// <summary>Gets a value indicating whether the PAGEUP key is currently down or not.</summary>
			static bool GetVK_PAGEUP();

			/// <summary>Gets a value indicating whether the PAUSE key is currently down or not.</summary>
			static bool GetVK_PAUSE();

			/// <summary>Gets a value indicating whether the PERIOD key is currently down or not.</summary>
			static bool GetVK_PERIOD();

			/// <summary>Gets a value indicating whether the PRINTSCREEN key is currently down or not.</summary>
			static bool GetVK_PRINTSCREEN();

			/// <summary>Gets a value indicating whether the Q key is currently down or not.</summary>
			static bool GetVK_Q();

			/// <summary>Gets a value indicating whether the R key is currently down or not.</summary>
			static bool GetVK_R();

			/// <summary>Gets a value indicating whether the RALT key is currently down or not.</summary>
			static bool GetVK_RALT();

			/// <summary>Gets a value indicating whether the RCTRL key is currently down or not.</summary>
			static bool GetVK_RCTRL();

			/// <summary>Gets a value indicating whether the RETURN key is currently down or not.</summary>
			static bool GetVK_RETURN();

			/// <summary>Gets a value indicating whether the RGUI key is currently down or not.</summary>
			static bool GetVK_RGUI();

			/// <summary>Gets a value indicating whether the RIGHT key is currently down or not.</summary>
			static bool GetVK_RIGHT();

			/// <summary>Gets a value indicating whether the RIGHTBRACKET key is currently down or not.</summary>
			static bool GetVK_RIGHTBRACKET();

			/// <summary>Gets a value indicating whether the RSHIFT key is currently down or not.</summary>
			static bool GetVK_RSHIFT();

			/// <summary>Gets a value indicating whether the S key is currently down or not.</summary>
			static bool GetVK_S();

			/// <summary>Gets a value indicating whether the SCROLLLOCK key is currently down or not.</summary>
			static bool GetVK_SCROLLLOCK();

			/// <summary>Gets a value indicating whether the SEMICOLON key is currently down or not.</summary>
			static bool GetVK_SEMICOLON();

			/// <summary>Gets a value indicating whether the SLASH key is currently down or not.</summary>
			static bool GetVK_SLASH();

			/// <summary>Gets a value indicating whether the SPACE key is currently down or not.</summary>
			static bool GetVK_SPACE();

			/// <summary>Gets a value indicating whether the T key is currently down or not.</summary>
			static bool GetVK_T();

			/// <summary>Gets a value indicating whether the TAB key is currently down or not.</summary>
			static bool GetVK_TAB();

			/// <summary>Gets a value indicating whether the U key is currently down or not.</summary>
			static bool GetVK_U();

			/// <summary>Gets a value indicating whether the UP key is currently down or not.</summary>
			static bool GetVK_UP();

			/// <summary>Gets a value indicating whether the V key is currently down or not.</summary>
			static bool GetVK_V();

			/// <summary>Gets a value indicating whether the W key is currently down or not.</summary>
			static bool GetVK_W();

			/// <summary>Gets a value indicating whether the X key is currently down or not.</summary>
			static bool GetVK_X();

			/// <summary>Gets a value indicating whether the Y key is currently down or not.</summary>
			static bool GetVK_Y();

			/// <summary>Gets a value indicating whether the Z key is currently down or not.</summary>
			static bool GetVK_Z();

			/// <summary>Gets the current X position of the mouse.</summary>
			static int GetMouseX();

			/// <summary>Gets the current Y position of the mouse.</summary>
			static int GetMouseY();

			/// <summary>Gets a value indicating whether Mouse1 is currently down or not.</summary>
			static bool GetMouse1();

			/// <summary>Gets a value indicating whether Mouse2 is currently down or not.</summary>
			static bool GetMouse2();

			/// <summary>Gets a value indicating whether Mouse3 is currently down or not.</summary>
			static bool GetMouse3();

			/// <summary>Gets a value indicating whether Mouse4 is currently down or not.</summary>
			static bool GetMouse4();

			/// <summary>Gets a value indicating whether Mouse5 is currently down or not.</summary>
			static bool GetMouse5();

			/// <summary>Gets the current position of the mouse wheel.</summary>
			static int GetMouseWheel();

		private:
			static bool VK_0;
			static bool VK_1;
			static bool VK_2;
			static bool VK_3;
			static bool VK_4;
			static bool VK_5;
			static bool VK_6;
			static bool VK_7;
			static bool VK_8;
			static bool VK_9;
			static bool VK_A;
			static bool VK_QUOTE;
			static bool VK_B;
			static bool VK_BACKSLASH;
			static bool VK_BACKSPACE;
			static bool VK_C;
			static bool VK_CAPSLOCK;
			static bool VK_COMMA;
			static bool VK_D;
			static bool VK_DELETE;
			static bool VK_DOWN;
			static bool VK_E;
			static bool VK_END;
			static bool VK_EQUALS;
			static bool VK_ESCAPE;
			static bool VK_F;
			static bool VK_F1;
			static bool VK_F10;
			static bool VK_F11;
			static bool VK_F12;
			static bool VK_F2;
			static bool VK_F3;
			static bool VK_F4;
			static bool VK_F5;
			static bool VK_F6;
			static bool VK_F7;
			static bool VK_F8;
			static bool VK_F9;
			static bool VK_G;
			static bool VK_BACKQUOTE;
			static bool VK_H;
			static bool VK_HOME;
			static bool VK_I;
			static bool VK_INSERT;
			static bool VK_J;
			static bool VK_K;
			static bool VK_KP_0;
			static bool VK_KP_1;
			static bool VK_KP_2;
			static bool VK_KP_3;
			static bool VK_KP_4;
			static bool VK_KP_5;
			static bool VK_KP_6;
			static bool VK_KP_7;
			static bool VK_KP_8;
			static bool VK_KP_9;
			static bool VK_KP_DIVIDE;
			static bool VK_KP_ENTER;
			static bool VK_KP_MINUS;
			static bool VK_KP_MULTIPLY;
			static bool VK_KP_PERIOD;
			static bool VK_KP_PLUS;
			static bool VK_L;
			static bool VK_LALT;
			static bool VK_LCTRL;
			static bool VK_LEFT;
			static bool VK_LEFTBRACKET;
			static bool VK_LGUI;
			static bool VK_LSHIFT;
			static bool VK_M;
			static bool VK_MINUS;
			static bool VK_N;
			static bool VK_NUMLOCKCLEAR;
			static bool VK_O;
			static bool VK_P;
			static bool VK_PAGEDOWN;
			static bool VK_PAGEUP;
			static bool VK_PAUSE;
			static bool VK_PERIOD;
			static bool VK_PRINTSCREEN;
			static bool VK_Q;
			static bool VK_R;
			static bool VK_RALT;
			static bool VK_RCTRL;
			static bool VK_RETURN;
			static bool VK_RGUI;
			static bool VK_RIGHT;
			static bool VK_RIGHTBRACKET;
			static bool VK_RSHIFT;
			static bool VK_S;
			static bool VK_SCROLLLOCK;
			static bool VK_SEMICOLON;
			static bool VK_SLASH;
			static bool VK_SPACE;
			static bool VK_T;
			static bool VK_TAB;
			static bool VK_U;
			static bool VK_UP;
			static bool VK_V;
			static bool VK_W;
			static bool VK_X;
			static bool VK_Y;
			static bool VK_Z;

			static int mouseX;
			static int mouseY;
			static bool mouse1;
			static bool mouse2;
			static bool mouse3;
			static bool mouse4;
			static bool mouse5;
			static int mouseWheel;
	};
}

#endif
