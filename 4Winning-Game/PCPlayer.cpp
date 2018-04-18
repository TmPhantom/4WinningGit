#include "PCPlayer.hpp"

PCPlayer::PCPlayer()
{
}


PCPlayer::~PCPlayer()
{
}

bool PCPlayer::pcPlayersTurn(PlayingField *pPlayingField, int *pLine) {
	return true;
}

bool PCPlayer::playerHasDoubleRow(PlayingField *pPlayingField, int *pLine) {

	std::list<std::pair<int, int>>::iterator it;

	return true;
}

bool PCPlayer::playerHasTrippleRow(PlayingField *pPlayingField, int *pLine) {

	std::list<std::pair<int, int>>::iterator it;
	std::list<std::pair<int, int>> playersCoins = pPlayingField->getPlayersCoins();
	std::list<std::pair<int, int>> coins = pPlayingField->getCoinsList();
	int counter = 1;
	int length = pPlayingField->getLength();
	int height = pPlayingField->getHeight();

	for (it = playersCoins.begin(); it != playersCoins.end(); it++) {
		int x = it->first;
		int y = it->second;

		//remember: 
		//	|	y = 0
		//	|
		//	|		++y
		//\   /
		// \ /
		//  *	y = 5

		while ((--y >= 0 && proofCoin(playersCoins, x, --y))) {
			counter++;
			if (counter == 3) {
				*pLine = x;
				return true;
			}
		}
		counter = 1;
		x = it->first;
		y = it->second;
		while ((++x <= length && --y >= 0 && proofCoin(playersCoins, ++x, --y))) {
			counter++;
			if (counter == 3 && proofCoin(coins, ++x, y)) {
				//3er Reihe gefunden...Überprüfe, ob die Reihe verhindert werden kann bzw. bereits verhindert wurde
				*pLine = x;
				return true;
			}
		}
		counter = 1;
		x = it->first;
		y = it->second;
		while ((++x <= length && proofCoin(playersCoins, ++x, y))) {
			counter++;
			if (counter == 3) {
				if (y == height) {
					*pLine = ++x;
					return true;
				}
				if (proofCoin(coins, x, ++y)) {
					*pLine = ++x;
					return true;
				}
			}
		}
		counter = 1;
		x = it->first;
		y = it->second;
		while ((++x <= length && ++y <= height && proofCoin(playersCoins, ++x, ++y))) {
			counter++;
			if (counter == 3) {
				if (y == height) {
					*pLine = x;
					return true;
				}
				if (proofCoin(coins, x, ++y)) {
					*pLine = x;
					return true;
				}
			}
		}
		counter = 1;
		x = it->first;
		y = it->second;
		while ((++y <= height && proofCoin(playersCoins, x, ++y))) {
			counter++;
			if (counter == 3) {
				if (y == height) {
					*pLine = x;
					return true;
				}
				if (proofCoin(coins, x, ++y)) {
					*pLine = x;
					return true;
				}
			}
		}
		counter = 1;
		x = it->first;
		y = it->second;
		while (++y <= height && --x >= 0 && proofCoin(playersCoins, --x, ++y)) {
			counter++;
			if (counter == 3) {
				if (y == height) {
					*pLine = x;
					return true;
				}
				if (proofCoin(coins, x, ++y)) {
					*pLine = x;
					return true;
				}
			}
		}
		counter = 1;
		x = it->first;
		y = it->second;
		while (--x >= 0 && proofCoin(playersCoins, --x, y)) {
			counter++;
			if (counter == 3) {
				if (y == height) {
					*pLine = x;
					return true;
				}
				if (proofCoin(coins, x, ++y)) {
					*pLine = x;
					return true;
				}
			}
		}
		counter = 1;
		x = it->first;
		y = it->second;
		while (--x >= 0 && --y >= 0 && proofCoin(playersCoins, --x, --y)) {
			counter++;
			if (counter == 3) {
				return true;
			}
		}
	}

	return false;
}

bool PCPlayer::proofCoin(std::list< std::pair<int, int>> &coins, int x, int y) {
	
	std::list<std::pair<int, int>>::iterator it;
	
	for (it = coins.begin(); it != coins.end(); it++) {
		//coin was found
		if (it->first == x && it->second == y) {
			return true;
		}
	}

	return false;
}