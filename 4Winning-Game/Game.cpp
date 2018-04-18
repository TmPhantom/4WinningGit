#include "Game.hpp"

Game::Game() {

}

void Game::run() {

	pPlayingField->initPlayingField();
	int pcLine;
	pPcPlayer = new PCPlayerHard();

	do {
		
		playersTurn();

		pPcPlayer->pcPlayersTurn(pPlayingField, &pcLine);

		pPlayingField->showPlayingField();
	} while (true);
}

bool Game::playersTurn() {
	
	int enter = 0;

	do {
		std::cout << "Your Enter" << std::endl;
		std::cin >> enter;
	} while (!(pPlayingField->proofEnter(enter)));

	if (!(setCoinInTable(enter, false))) {
		return false;
	}

	return true;
}

bool Game::setCoinInTable(int xEnter, bool pc) {
	
	//if line is empty
	if (pPlayingField->getFieldState(xEnter, yMax) == State::FREE) {
		if (pc) {
			pPlayingField->setFieldState(xEnter, yMax, State::PC);
			pPlayingField->addPairToList(xEnter, yMax, true);
		}

		pPlayingField->setFieldState(xEnter, yMax, State::YOURS);
		pPlayingField->addPairToList(xEnter, yMax, false);

		return true;
	}

	//if already some coins are in line
	if (pPlayingField->getFieldState(xEnter, yMax) != State::FREE) {

		for (int y = 0; y <= yMax; y++) {

			if (pPlayingField->getFieldState(xEnter, y) != State::FREE) {

				if (pc) {
					pPlayingField->setFieldState(xEnter, y - 1, State::PC);
					pPlayingField->addPairToList(xEnter, y - 1, true);

					if (y - 1 == 0) {
						pPlayingField->addLineToList(xEnter);
					}
					return true;
				}
				
				if (!pc) {
					pPlayingField->setFieldState(xEnter, y - 1, State::YOURS);
					pPlayingField->addPairToList(xEnter, y - 1, false);

					if (y - 1 == 0) {
						pPlayingField->addLineToList(xEnter);
					}
					return true;
				}
			}
		}
	}

	std::cout << "ERROR:: setCoinInTable-Function" << std::endl;
	return false;
}