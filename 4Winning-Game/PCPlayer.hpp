#pragma once
#include "PlayingField.hpp"
#include <list>

class PCPlayer
{
public:
	PCPlayer();
	virtual ~PCPlayer();

	virtual bool pcPlayersTurn(PlayingField *pPlayingField, int *pLine);
	
protected:
	//pLine gives the selecting line back
	bool playerHasDoubleRow(PlayingField *pPlayingField, int *pLine);
	bool playerHasTrippleRow(PlayingField *pPlayingField, int *pLine);
	bool proofCoin(std::list< std::pair<int, int>> &coins, int x, int y);
	bool randomAttack(PlayingField *pPlayingFiel);

private:
};

