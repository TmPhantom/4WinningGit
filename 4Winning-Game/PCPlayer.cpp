#include "PCPlayer.hpp"
#include <ctime>

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

	std::list<std::pair<int, int>> playersCoins = pPlayingField->getPlayersCoins();
	std::list<std::pair<int, int>>::iterator it = playersCoins.begin();
	std::list<std::pair<int, int>> coins = pPlayingField->getCoinsList();
	int counter = 1;
	int length = pPlayingField->getLength();
	int height = pPlayingField->getHeight();

	for (it; it != playersCoins.end(); it++) {
		int x = it->first;
		int y = it->second;

		//remember: 
		//	|	     y = 0
		//	|
		//	|		++y
		//\   /
		// \ /
		//  *	y = 5
		
		while ((--y >= 0 && proofCoin(playersCoins, x, --y))) {
			counter++;
			if (counter == 3) {
				pPlayingField->setCoinInTable(x, true);
				return true;
			}
		}
		counter = 1;
		x = it->first;
		y = it->second;
		while ((++x <= length && --y >= 0 && proofCoin(playersCoins, ++x, --y))) {
			counter++;
			if (counter == 3 && proofCoin(coins, ++x, y)) {
				//3er Reihe gefunden...�berpr�fe, ob die Reihe verhindert werden kann bzw. bereits verhindert wurde
				pPlayingField->setCoinInTable(x, true);
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
					pPlayingField->setCoinInTable(x, true);
					return true;
				}
				if (proofCoin(coins, x, ++y)) {
					pPlayingField->setCoinInTable(x, true);
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
					pPlayingField->setCoinInTable(x, true);
					return true;
				}
				if (proofCoin(coins, x, ++y)) {
					pPlayingField->setCoinInTable(x, true);
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
					pPlayingField->setCoinInTable(x, true);
					return true;
				}
				if (proofCoin(coins, x, ++y)) {
					pPlayingField->setCoinInTable(x, true);
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
					pPlayingField->setCoinInTable(x, true);
					return true;
				}
				if (proofCoin(coins, x, ++y)) {
					pPlayingField->setCoinInTable(x, true);
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
					pPlayingField->setCoinInTable(x, true);
					return true;
				}
				if (proofCoin(coins, x, ++y)) {
					pPlayingField->setCoinInTable(x, true);
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

// support function for playerHasTrippleRow
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

bool PCPlayer::randomAttack(PlayingField *pPlayingField) {

	int length = pPlayingField->getLength();
	int height = pPlayingField->getHeight();
	std::list<int> linesList = pPlayingField->getLinesList();
	std::list<int>::iterator it;

	srand(static_cast<unsigned int>(time(NULL)));

	int xValue = rand() % length;

	//check if the randomly choiced xValue is already occupied
	for (it = linesList.begin(); it != linesList.end(); it++) {
		
		if (xValue == *it) {
			xValue = xValue + 1 % length;
			it = linesList.begin();
		}
	}

	pPlayingField->setCoinInTable(xValue, true);
	return true;
}