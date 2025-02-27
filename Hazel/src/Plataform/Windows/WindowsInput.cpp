#include "hzpch.h"
#include "WindowsInput.h"

#include "Hazel/Application.h"

#include <GLFW/glfw3.h>
#include <Hazel/KeyCodes.h>

#ifdef _WIN32
#include <windows.h>
#endif

namespace Hazel {
	
	Input* Input::s_Instance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(const KeyCode key)  {
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_PRESS;
    } 

    bool WindowsInput::IsMouseButtonPressedImpl(int button) {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);

        return state == GLFW_PRESS;
    }

	std::pair<float, float>WindowsInput::GetMousePositionImpl() {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return std::pair<float, float>((float)xpos, (float)ypos);
	}

	float WindowsInput::GetMouseXImpl() {
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl() {
		auto [x, y] = GetMousePositionImpl();
		return y;
	}
}
