#include "pch.h"

#include "Picture.h"
#include "GLFWCode/OpenGLPicture.h"

namespace egg
{
	Picture::Picture(const std::string& fileName)
	{
#ifdef EGG_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(fileName) };
#elif EGG_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(fileName) };
#elif EGG_LINUX
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(fileName) };
#endif
	}

//	Picture::Picture(std::string&& fileName)
//	{
//#ifdef EGG_MSCPP
//		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(move(fileName)) };
//#elif EGG_APPLE
//		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(move(fileName)) };
//#elif EGG_LINUX
//		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(move(fileName)) };
//#endif
//	}

	void Picture::Bind() {
		mImplementation->Bind();
	}

	int Picture::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int Picture::GetHeight() const
	{
		return mImplementation->GetHeight();
	}
}