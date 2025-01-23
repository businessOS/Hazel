#pragma once

#include "Hazel/Events/Event.h"

#include <sstream>

namespace Hazel {

	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Hazel Engine",
			uint32_t width = 1600,
			uint32_t height = 900)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	// This is a pure virtual class, 
	// meaning that it has no implementation and his implimentation will be based on the platform *Windows, Linux, Mac*
	
    class HAZEL_API Window
    {
        public:
            using EventCallbackFn = std::function<void(Event&)>;

            virtual ~Window() = default;

            virtual void OnUpdate() = 0;

            virtual uint32_t GetWidth() const = 0;
            virtual uint32_t GetHeight() const = 0;

            // Window attributes
            virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
            virtual void SetVSync(bool enabled) = 0;
            virtual bool IsVSync() const = 0;

            virtual void* GetNativeWindow() const = 0;

			// Future implementation in the cpp file for the difents platform *Windows, Linux, Mac*
			// Factory method to create a window based on the platform
            static Window* Create(const WindowProps& props = WindowProps());
        };

}