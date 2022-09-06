#pragma once

//
//			Application Class
// 
// Application class is the base class for all client application. All client applications should derrive from this class.
// Application has few methods 
// 
//	Start() -> runs before the application start to run.
//	Run() -> runs the application and main loop.
//	Loop() -> runs in every frame.
//	Event callbacks -> runs when event occurs.
//

#include "core.h"
#include "Window.h"
#include "RE/core/Event/Event.h"

#include <string>

namespace RE {

	class RE_API Application
	{

	public:
		Application(const std::string title, uint32_t width, uint32_t height);
		void OnEvent(Event* e) const;
		virtual ~Application();

		virtual void Run();		// starts the application
		virtual void Start();	// runs at begining
		virtual void Loop();	// runs in every frame

		//Event callbacks
		virtual void OnWindowClosed(WindowClosed* e) const;
		virtual void OnWindowResized(WindowResized* e) const {}
		virtual void OnKeyPressed(KeyPressed* e) const {}
		virtual void OnKeyReleased(KeyReleased* e) const {}
		virtual void OnMouseMoved(MouseMoved* e) const {}
		virtual void OnMouseButtonPressed(MouseButtonPressed* e) const {}
		virtual void OnMouseButtonReleased(MouseButtonReleased* e) const {}

		inline Window* GetWindow() const { return m_Window; }

	protected:
		mutable bool m_Running = false;

	private:
		std::string m_Title;
		uint32_t m_Width, m_Height;

		Window* m_Window;

	public:
		static Application* INSTANCE;

	};

}

