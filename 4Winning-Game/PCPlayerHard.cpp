#include "PCPlayerHard.hpp"


PCPlayerHard::PCPlayerHard()
{
}


PCPlayerHard::~PCPlayerHard()
{
}

bool PCPlayerHard::pcPlayersTurn(PlayingField *pPlayingField, int *pLine) {

	int xValue;

	if (playerHasTrippleRow(pPlayingField, pLine)) {
		return true;
	}

	randomAttack(pPlayingField);

	return true;
}

