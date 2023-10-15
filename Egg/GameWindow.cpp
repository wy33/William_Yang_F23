#include "pch.h"

#include "GameWindow.h"
#include "GLFWCode/GLFWImplementation.h"

namespace egg
{
	GameWindow::GameWindow()
	{
		// Cannot assign unique_ptr to raw pointer
		// Create temp unique_ptr to WindowImplementation object
		// Pass it a constructor
		// The unique_ptr does the move mechanics automatically
		// WindowImplementation object -> GLFWImplementation/etc object
#ifdef EGG_MSCPP
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif EGG_APPLE
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif EGG_LINUX
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#endif
	}

	void GameWindow::Create(const std::string& name, int width, int height)
	{
		mImplementation->Create(name, width, height);
	}

	int GameWindow::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	int GameWindow::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	void GameWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	void GameWindow::PollEvents()
	{
		mImplementation->PollEvents();
	}
}