#include "PCPlayerHard.hpp"


PCPlayerHard::PCPlayerHard()
{
}


PCPlayerHard::~PCPlayerHard()
{
}

bool PCPlayerHard::pcPlayersTurn(PlayingField *pPlayingField, int *pLine) {

	if (playerHasTrippleRow(pPlayingField, pLine)) {
		return true;
	}
	return true;
}

