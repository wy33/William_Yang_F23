#pragma once

#include "pch.h"

//#include "Egg.h"
#include "Utilities.h"
#include "GameWindow.h"
#include "Shader.h"
#include "Picture.h"
#include "Renderer.h"
#include "Unit.h"

//#include "../glad/include/glad/glad.h"
//#include "../glfw/include/GLFW/glfw3.h"
//#include "../stbi/stb_image.h"

namespace egg
{
	constexpr int FPS{ 60 };

	template<typename T>
	class EggApp
	{
	public:
		static void Init();
		static void RunInterface();

		static void Draw(int x, int y, Picture& pic);
		static void Draw(Unit& item);

		void Run();
		virtual void OnUpdate() = 0;	// Generates 1 frame every run

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

		void DefaultWindowCloseHandler();

		friend typename T;

	private:
		EggApp();	// Singleton class, hide default constructor

		inline static EggApp* sInstance{ nullptr };		// Pointer to singleton instance

		GameWindow mWindow;			// Window

		Renderer mRenderer;			// Renderer

		bool mShouldContinue{ true };	// Determines if app continues to run

		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;

	};

	template<typename T>
	EggApp<T>::EggApp()
	{
		mWindow.Create("Game WY", 1000, 800);

		mRenderer.Init();

		// Set up window close procedure
		SetWindowCloseCallback([this]() { DefaultWindowCloseHandler(); });
	}

	template<typename T>
	void EggApp<T>::Init() {
		if (sInstance == nullptr)
			sInstance = new T;
	}

	template<typename T>
	void EggApp<T>::RunInterface()
	{
		sInstance->Run();
	}

	template<typename T>
	void EggApp<T>::Run()
	{
		//////////////////// Shaders ////////////////////

		egg::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultfragmentShader.glsl" };

		//////////////////// Textures ////////////////////

		//egg::Picture pic{ "../Assets/Images/test.png" };

		mNextFrameTime = std::chrono::steady_clock::now();

		while (mShouldContinue)
		{
			mRenderer.Clear();

			// 11/27

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());
			//pic.Bind();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}

	}

	template<typename T>
	void EggApp<T>::OnUpdate()
	{
	}

	template<typename T>
	void EggApp<T>::Draw(int x, int y, Picture& pic)
	{
		sInstance->mRenderer.Draw(x, y, pic);
	}

	template<typename T>
	void EggApp<T>::Draw(Unit& item)
	{
		sInstance->mRenderer.Draw(item.mXPosition, item.mYPosition, item.mImage);
	}

	template<typename T>
	void EggApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mWindow.SetKeyPressedCallback(callbackFunc);
	}

	template<typename T>
	void EggApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}

	template<typename T>
	void EggApp<T>::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		mWindow.SetWindowCloseCallback(callbackFunc);
	}

	template<typename T>
	void EggApp<T>::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}
}
