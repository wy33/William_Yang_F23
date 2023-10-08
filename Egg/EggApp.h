#pragma once

#include "pch.h"
#include "Utilities.h"

namespace egg
{
	template<typename T>
	class EGG_API EggApp
	{
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate() = 0;	// Generates 1 frame every run

		friend typename T;

	private:
		EggApp();	// Singleton class, hide default constructor

		inline static EggApp* sInstance{ nullptr };		// Pointer to singleton instance

		bool mShouldContinue{ true };	// Determines if app continues to run

	};

	template<typename T>
	EggApp<T>::EggApp()
	{
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
		while (mShouldContinue)
		{
			OnUpdate();
		}
	}

	template<typename T>
	void EggApp<T>::OnUpdate()
	{
	}
	
}

/*
#include "EggApp.cpp"

namespace egg
{
	template<typename T>
	class EGG_API EggApp
	{
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate() = 0;	// Generates 1 frame every run

	private:
		EggApp();	// Singleton class, hide default constructor

		inline static EggApp* sInstance{ nullptr };		// Pointer to singleton instance

		bool mShouldContinue{ true };	// Determines if app continues to run

	};
}

#include "EggApp.cpp"
*/