#pragma once
#include "PCPlayerHard.hpp"

class Game {

	private:
		PlayingField *pPlayingField = new PlayingField();
		PCPlayer *pPcPlayer;
		int xMax = pPlayingField->getXMax();
		int yMax = pPlayingField->getYMax();

	public:
		Game();
		void run();

		bool playersTurn();
		bool setCoinInTable(int xEnter, bool pc);
};