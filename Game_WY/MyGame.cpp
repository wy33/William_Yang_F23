#include<random>

#include "MyGame.h"

#include "Coconut.h"
#include "Timer.h"

MyGame::MyGame()
{
	// Set key bindings
	SetKeyPressedCallback([this](const egg::KeyPressed& e) { OnKeyPress(e); });
	SetKeyReleasedCallback([this](const egg::KeyReleased& e) { OnKeyRelease(e); });

	// Create and store all digit images
	mDigits.emplace_back(egg::Picture("../Assets/Images/0.png"));
	mDigits.emplace_back(egg::Picture("../Assets/Images/1.png"));
	mDigits.emplace_back(egg::Picture("../Assets/Images/2.png"));
	mDigits.emplace_back(egg::Picture("../Assets/Images/3.png"));
	mDigits.emplace_back(egg::Picture("../Assets/Images/4.png"));
	mDigits.emplace_back(egg::Picture("../Assets/Images/5.png"));
	mDigits.emplace_back(egg::Picture("../Assets/Images/6.png"));
	mDigits.emplace_back(egg::Picture("../Assets/Images/7.png"));
	mDigits.emplace_back(egg::Picture("../Assets/Images/8.png"));
	mDigits.emplace_back(egg::Picture("../Assets/Images/9.png"));

	std::srand(std::time(nullptr));
}

void MyGame::OnUpdate()
{
	Draw(0, 0, mBackground);

	// Only draw game if the game isn't over
	if (!mGameOver)
	{
		// Spawn coconut
		if (ShouldSpawn())
			SpawnCoconut();

		// Update coconuts
		for (auto& coconut : mCoconuts)
		{
			// Use speed to update falling coconut
			coconut.UpdateYCoord(-coconut.GetSpeed());
			Draw(coconut);
		}

		// Remove coconuts that are off screen
		// Increment counter when coconut is removed
		for (int i = mCoconuts.size() - 1; i - 1 >= 0; i--)
		{
			if (mCoconuts[i].GetYCoord() < 0)
			{
				mCoconuts.erase(mCoconuts.begin() + i);
				mCounter++;
			}
		}

		UpdateSealPosition();

		CheckCollisions();
	}

	Draw(mSeal);

	// Draw score
	DrawCounter();

	// Check if game is over
	// Draw GAME OVER screen if it is
	CheckGameOver();
	
}

void MyGame::UpdateSealPosition()
{
	if (mState != State::MOVE)
		return;

	switch (mDirection)
	{
		case Direction::LEFT:
			if(mSeal.GetXCoord() > 0)
				mSeal.UpdateXCoord(std::max(-50, -mSeal.GetXCoord()));
			return;
		case Direction::RIGHT:
			if(mSeal.GetXCoord() < GetWindowWidth() - mSeal.GetWidth())
				mSeal.UpdateXCoord(std::min(50, GetWindowWidth() - mSeal.GetXCoord() + mSeal.GetWidth()));
			return;
	}
}

void MyGame::OnKeyPress(const egg::KeyPressed& e)
{
	switch (e.GetKeyCode())
	{
		case EGG_KEY_LEFT:
			mDirection = Direction::LEFT;
			mState = State::MOVE;
			return;
		case EGG_KEY_RIGHT:
			mDirection = Direction::RIGHT;
			mState = State::MOVE;
			return;
		default:
			return;
	}

}

void MyGame::OnKeyRelease(const egg::KeyReleased& e)
{
	mState = State::STOP;
}

void MyGame::SpawnCoconut()
{
	std::string coconutPath{ "" };

	switch (std::rand() % 2 == 0)
	{
	case 0:
		coconutPath = "../Assets/Images/coconut.png";
		break;
	case 1:
		coconutPath = "../Assets/Images/coconuts.png";
		break;
	default:
		coconutPath = "../Assets/Images/coconut.png";
		break;
	}

	// Get the max x Position for both coconuts
	int maxXPosition{ GetWindowWidth() - egg::Picture(coconutPath).GetWidth() };

	// Start speed: 5-20
	// Max difficulty speed (capped): 15-30
	mCoconuts.emplace_back(Coconut(coconutPath,
		std::rand() % maxXPosition,
		GetWindowHeight(), (std::rand() % 16) + std::max(mDifficulty * 2, 10) + 5));
}

void MyGame::DrawCounter()
{
	int number = mCounter;
	int slot = 1;	// Determines the screen position of the digit

	// Corner case: if score is 0 then draw 0
	if (number == 0)
		DrawDigit(0, 1);

	while (number > 0)
	{
		DrawDigit(number % 10, slot);
		number /= 10;
		slot++;
	}
}

// Check if seal collides with any coconuts
// If collision detected, then mark the game as over
void MyGame::CheckCollisions()
{
	for (auto& coconut : mCoconuts)
	{
		if (UnitsOverlap(coconut, mSeal))
			mGameOver = true;
	}
}

// If the game is over, display the game over image
void MyGame::CheckGameOver()
{
	if (mGameOver)
	{
		Draw((GetWindowWidth() / 2) - (mGameOverPicture.GetWidth() / 2),
			(GetWindowHeight() / 2) - (mGameOverPicture.GetHeight() / 2),
			mGameOverPicture);
	}
}

// Draw the individual digit to the screen given the digit and the slot position on screen
void MyGame::DrawDigit(int digit, int slot)
{
	int windowWidth = GetWindowWidth();
	int windowHeight = GetWindowHeight();

	int digitWidth = mDigits[0].GetWidth();
	int digitHeight = mDigits[0].GetHeight();

	int xPosition = windowWidth - (digitWidth * slot);
	int yPosition = windowHeight - digitHeight;

	switch (digit)
	{
		case 0:
			Draw(xPosition, yPosition, mDigits[0]);
			return;
		case 1:
			Draw(xPosition, yPosition, mDigits[1]);
			return;
		case 2:
			Draw(xPosition, yPosition, mDigits[2]);
			return;
		case 3:
			Draw(xPosition, yPosition, mDigits[3]);
			return;
		case 4:
			Draw(xPosition, yPosition, mDigits[4]);
			return;
		case 5:
			Draw(xPosition, yPosition, mDigits[5]);
			return;
		case 6:
			Draw(xPosition, yPosition, mDigits[6]);
			return;
		case 7:
			Draw(xPosition, yPosition, mDigits[7]);
			return;
		case 8:
			Draw(xPosition, yPosition, mDigits[8]);
			return;
		case 9:
			Draw(xPosition, yPosition, mDigits[9]);
			return;
	}
}

bool MyGame::ShouldSpawn() const
{
	if (std::rand() % 100 < 5 + (mDifficulty * 2))
		return true;

	return false;
}
