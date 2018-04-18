#include "PlayingField.hpp"

PlayingField::PlayingField() {}

PlayingField::~PlayingField() {}

void PlayingField::initPlayingField() {

	for (int x = 0; x < length; x++) {
		for (int y = 0; y < height; y++) {
			playingField[x][y].setState(State::FREE);
		}
	}
}

void PlayingField::showPlayingField() {

	for (int x = 0; x < length; x++) {
		std::cout << " " << x;
	}
	std::cout << std::endl;
	for (int y = 0; y < height; y++) {

		for (int x = 0; x < length; x++) {
			
			switch (playingField[x][y].getState()) {
				case (State::FREE) :
					std::cout << " .";
					break;
				case (State::YOURS) :
					std::cout << " X";
					break;
				case (State::PC) :
					std::cout << " 0";
					break;
			}
		}
		std::cout << std::endl;
	}
}

bool PlayingField::proofLine(int xLine) {

	std::list<int>::iterator i;

	for (i = linesList.begin(); i != linesList.end(); i++) {

		if (*i == xLine) {
			std::cout << "This Line is already full. It's not possible to select" << std::endl;
			return false;
		}
	}
	return true;
}

bool PlayingField::proofEnter(int xEnter) {
	if (0 <= xEnter && xEnter <= xMax && proofLine(xEnter)) {
		return true;
	}
	return false;
}

void PlayingField::addPairToList(int x, int y, bool pc) {
	
	std::pair<int, int> coinsEntry;
	coinsEntry.first = x;
	coinsEntry.second = y;

	if (pc) {
		it = coins.find(pcKey);
		//
		if (it != coins.end()) {
			std::list<std::pair<int, int>> list = it->second;
			list.push_front(coinsEntry);
			it->second = list;
		}
		//if the list is empty
		else {
			std::list<std::pair<int, int>> list;
			list.push_front(coinsEntry);
			coins.insert(std::pair<int, std::list<std::pair<int, int>>>(pcKey, list));
		}
	}
	if (!pc) {
		it = coins.find(playersKey);
		if (it != coins.end()) {
			std::list<std::pair<int, int>> list = it->second;
			list.push_front(coinsEntry);
			it->second = list;
		}
		//if the list is empty
		else {
			std::list<std::pair<int, int>> list;
			list.push_front(coinsEntry);
			coins.insert(std::pair<int, std::list<std::pair<int, int>>>(playersKey, list));
		}
	}
}

//Getter and Setter

void PlayingField::setFieldState(int xPos, int yPos, State state) {
	playingField[xPos][yPos].setState(state);
}

int PlayingField::getHeight() {
	return height;
}

int PlayingField::getLength() {
	return length;
}

State PlayingField::getFieldState(int xPos, int yPos) {
	return playingField[xPos][yPos].getState();
}

void PlayingField::addLineToList(int xEnter) {
	linesList.push_back(xEnter);
}

std::list<int> PlayingField::getLinesList() {
	return linesList;
}

int PlayingField::getXMax() {
	return xMax;
}

int PlayingField::getYMax() {
	return yMax;
}

std::map<int, std::list<std::pair<int, int>>> PlayingField::getCoins() {
	return coins;
}

std::list<std::pair<int, int>> PlayingField::getPlayersCoins() {
	it = coins.find(playersKey);
	return it->second;
}

std::list<std::pair<int, int>> PlayingField::getPCCoins() {
	it = coins.find(pcKey);
	return it->second;
}

std::list< std::pair<int, int>> PlayingField::getCoinsList() {
	std::list<std::pair<int, int>> returnList = getPlayersCoins();
	std::list<std::pair<int, int>> pcCoins = getPCCoins();
	std::list<std::pair<int, int>>::iterator i;
	
	//put both lists together
	for (i = pcCoins.begin(); i != pcCoins.end(); i++) {
		returnList.push_back(*i);
	}
	return returnList;
}