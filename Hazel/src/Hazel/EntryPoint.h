#pragma once

//--- Fabric design pattern ---///
	

#ifdef HZ_PLATFORM_WINDOWS

#include <stdio.h>

// this is used to declare the CreateApplication function that is implemented in the Sandbox project
// with this (extern) we are telling the compiler that this function is implemented elsewhere
extern Hazel::Application* Hazel::CreateApplication();

// this is the entry point of the application
// When the client application return new Sandbox() class of type public Hazel::Application automatically execute this main function
int main(int argc, char** argv)
{
	Hazel::Log::Init();

    HZ_CORE_WARN("Initialized Log!");
	int a = 5;
    HZ_INFO("Hello VAR={0}", a);

    auto *app = Hazel::CreateApplication();

	// if app is not present in the Sandbox project or other client application project, then it will be nullptr
    if (!app) {
        printf("Error: CreateApplication returned is not present in your main aplication or not return an instance of the class\n");
        return -1;
    }
    app->Run();
    delete app;
    return 0;
}
#endif

//This is the exact order Output of the fabric pattern:
//1.- main function tell to the compiler that this archive contain an entry point of the solutions. (Hazel.dll EntryPoint.h)
//2.- CreateApplication Sandbox is running (SandboxApp.cpp)
//3.- Application Constructor (Hazel.dll Application)
//4.- Constructor Sandbox is running (Hazel.dll class contructor SandboxApp.cpp)
//5.- Application is running (Hazel.dll  Application::run)

