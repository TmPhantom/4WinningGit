#pragma once
#include "PCPlayer.hpp"

class PCPlayerHard : public PCPlayer
{
public:
	PCPlayerHard();
	~PCPlayerHard();

	bool pcPlayersTurn(PlayingField *pPlayingField, int *pLine);
};

