#pragma once

//
//			sfml_Window
// This is the main native window class for the Raavana Engine. this creates a 
// native window for render graphics.
// This can listen to various events and inputs. when they occures this class propergate those events
// to proper callback methods.
//

#include "RE/Window.h"

#include <SFML/Graphics.hpp>

namespace RE {

	class sfml_Window : public Window {

	public:
		sfml_Window(const std::string title, uint32_t width, uint32_t height);
		~sfml_Window();

		void EventManager(); // listen events and propergate them
		void Update() override;	// clear update the framebuffer

		inline void* GetNativeWindow() const override { return m_NativeWindow; }

	private:
		std::string m_Title;
		uint32_t m_Width, m_Height;

		sf::RenderWindow* m_NativeWindow;

	};

}