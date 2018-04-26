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

	if (!(pPlayingField->setCoinInTable(enter, false))) {
		return false;
	}

	return true;
}