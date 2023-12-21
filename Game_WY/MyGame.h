#pragma once

#include "Egg.h"

#include "Coconut.h"
#include "Timer.h"

class MyGame : public egg::EggApp<MyGame>
{
public:
	MyGame();

	virtual void OnUpdate() override;

	void UpdateSealPosition();

	void OnKeyPress(const egg::KeyPressed& e);
	void OnKeyRelease(const egg::KeyReleased& e);

	void SpawnCoconut();

	void DrawCounter();

	void CheckCollisions();

	void CheckGameOver();

private:
	enum class State { STOP, MOVE } mState;		// Init to State::STOP
	enum class Direction { LEFT = 0, RIGHT = 1 } mDirection;

	egg::Picture mBackground{ "../Assets/Images/background.png" };
	egg::Unit mSeal{ "../Assets/Images/seal.png", 20, 20 };

	std::vector<Coconut> mCoconuts;		// Coconuts on the screen
	std::vector<egg::Picture> mDigits;	// Images of digits: 0-9

	int mCounter{ 0 };

	int mDifficulty{ 0 };

	Timer mTimer;

	egg::Picture mGameOverPicture{ "../Assets/Images/game_over.png" };
	bool mGameOver{ false };		// Determines if game is over



	void DrawDigit(int digit, int slot);

	bool ShouldSpawn() const;

};