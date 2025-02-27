#include "hzpch.h"
#include "ImGuiLayer.h"
#include <GLFW/glfw3.h>	

#include  "Plataform/OpenGL/ImGuiOpenGLRenderer.h"
#include "Hazel/Application.h"
#include "Hazel/Core.h"

namespace Hazel {
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}
	void ImGuiLayer::OnAttach()
	{
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsLight();

		ImGui_ImplOpenGL3_Init("#version 410");
		// Setup Platform/Renderer backends
		

	}
	void ImGuiLayer::OnDetach()
	{
	}
	void ImGuiLayer::OnUpdate()
	{
		

		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());


		
		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();
		
		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

    static ImGuiKey MapGLFWKeyToImGuiKey(int keycode)  
    {  
       switch (keycode)  
       {  
       case GLFW_KEY_TAB: return ImGuiKey_Tab;  
       case GLFW_KEY_LEFT: return ImGuiKey_LeftArrow;  
       case GLFW_KEY_RIGHT: return ImGuiKey_RightArrow;  
       case GLFW_KEY_UP: return ImGuiKey_UpArrow;  
       case GLFW_KEY_DOWN: return ImGuiKey_DownArrow;  
       case GLFW_KEY_PAGE_UP: return ImGuiKey_PageUp;  
       case GLFW_KEY_PAGE_DOWN: return ImGuiKey_PageDown;  
       case GLFW_KEY_HOME: return ImGuiKey_Home;  
       case GLFW_KEY_END: return ImGuiKey_End;  
       case GLFW_KEY_INSERT: return ImGuiKey_Insert;  
       case GLFW_KEY_DELETE: return ImGuiKey_Delete;  
       case GLFW_KEY_BACKSPACE: return ImGuiKey_Backspace;  
       case GLFW_KEY_SPACE: return ImGuiKey_Space;  
       case GLFW_KEY_ENTER: return ImGuiKey_Enter;  
       case GLFW_KEY_ESCAPE: return ImGuiKey_Escape;  
       case GLFW_KEY_A: return ImGuiKey_A;  
       case GLFW_KEY_B: return ImGuiKey_B;  
       case GLFW_KEY_C: return ImGuiKey_C;  
       case GLFW_KEY_D: return ImGuiKey_D;  
       case GLFW_KEY_E: return ImGuiKey_E;  
       case GLFW_KEY_F: return ImGuiKey_F;  
       case GLFW_KEY_G: return ImGuiKey_G;  
       case GLFW_KEY_H: return ImGuiKey_H;  
       case GLFW_KEY_I: return ImGuiKey_I;  
       case GLFW_KEY_J: return ImGuiKey_J;  
       case GLFW_KEY_K: return ImGuiKey_K;  
       case GLFW_KEY_L: return ImGuiKey_L;  
       case GLFW_KEY_M: return ImGuiKey_M;  
       case GLFW_KEY_N: return ImGuiKey_N;  
       case GLFW_KEY_O: return ImGuiKey_O;  
       case GLFW_KEY_P: return ImGuiKey_P;  
       case GLFW_KEY_Q: return ImGuiKey_Q;  
       case GLFW_KEY_R: return ImGuiKey_R;  
       case GLFW_KEY_S: return ImGuiKey_S;  
       case GLFW_KEY_T: return ImGuiKey_T;  
       case GLFW_KEY_U: return ImGuiKey_U;  
       case GLFW_KEY_V: return ImGuiKey_V;  
       case GLFW_KEY_W: return ImGuiKey_W;  
       case GLFW_KEY_X: return ImGuiKey_X;  
       case GLFW_KEY_Y: return ImGuiKey_Y;  
       case GLFW_KEY_Z: return ImGuiKey_Z;  
       case GLFW_KEY_0: return ImGuiKey_0;  
       case GLFW_KEY_1: return ImGuiKey_1;  
       case GLFW_KEY_2: return ImGuiKey_2;  
       case GLFW_KEY_3: return ImGuiKey_3;  
       case GLFW_KEY_4: return ImGuiKey_4;  
       case GLFW_KEY_5: return ImGuiKey_5;  
       case GLFW_KEY_6: return ImGuiKey_6;  
       case GLFW_KEY_7: return ImGuiKey_7;  
       case GLFW_KEY_8: return ImGuiKey_8;  
       case GLFW_KEY_9: return ImGuiKey_9;  
       case GLFW_KEY_COMMA: return ImGuiKey_Comma;  
       case GLFW_KEY_PERIOD: return ImGuiKey_Period;  
       case GLFW_KEY_SEMICOLON: return ImGuiKey_Semicolon;  
       case GLFW_KEY_APOSTROPHE: return ImGuiKey_Apostrophe;  
       case GLFW_KEY_SLASH: return ImGuiKey_Slash;  
       case GLFW_KEY_BACKSLASH: return ImGuiKey_Backslash;  
       case GLFW_KEY_LEFT_BRACKET: return ImGuiKey_LeftBracket;  
       case GLFW_KEY_RIGHT_BRACKET: return ImGuiKey_RightBracket;  
       case GLFW_KEY_MINUS: return ImGuiKey_Minus;  
       case GLFW_KEY_EQUAL: return ImGuiKey_Equal;  
       case GLFW_KEY_GRAVE_ACCENT: return ImGuiKey_GraveAccent;  
       default: return ImGuiKey_None;  
       }  
    }

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));

	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.AddMouseButtonEvent(0, true);

		return false;
	}
	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.AddMouseButtonEvent(0, false);

		return false;
	}
	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		return false;
	}
	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH = e.GetXOffset();
		io.MouseWheel = e.GetYOffset();

		return false;

	}
    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e){

            ImGuiIO& io = ImGui::GetIO();
            int keycode = e.GetKeyCode();
            ImGuiKey imgui_key = MapGLFWKeyToImGuiKey(keycode);
            if (imgui_key != ImGuiKey_None)
            {
                io.AddKeyEvent(imgui_key, true);
            }

            io.KeyCtrl = io.KeysData[GLFW_KEY_LEFT_CONTROL].Down || io.KeysData[GLFW_KEY_RIGHT_CONTROL].Down;
            io.KeyShift = io.KeysData[GLFW_KEY_LEFT_SHIFT].Down || io.KeysData[GLFW_KEY_RIGHT_SHIFT].Down;
            io.KeyAlt = io.KeysData[GLFW_KEY_LEFT_ALT].Down || io.KeysData[GLFW_KEY_RIGHT_ALT].Down;
            io.KeySuper = io.KeysData[GLFW_KEY_LEFT_SUPER].Down || io.KeysData[GLFW_KEY_RIGHT_SUPER].Down;

            return false;
     }

    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e) {
            ImGuiIO& io = ImGui::GetIO();
            int keycode = e.GetKeyCode();
            ImGuiKey imgui_key = MapGLFWKeyToImGuiKey(keycode);
            if (imgui_key != ImGuiKey_None)
            {
                io.AddKeyEvent(imgui_key, false);
            }

            return false;
    }

	bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e) 
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();
		//ImGuiKey imgui_key = MapGLFWKeyToImGuiKey(keycode);
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter((unsigned short)keycode);

		return false;
	}

	bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());

		return false;
	}
}	
