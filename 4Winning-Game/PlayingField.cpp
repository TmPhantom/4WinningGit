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
				case (State::PLAYER) :
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
		pcCoins.push_front(coinsEntry);
	}
	if (!pc) {
		playersCoins.push_front(coinsEntry);
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
	return playersCoins;
}

std::list<std::pair<int, int>> PlayingField::getPCCoins() {
	return pcCoins;
}

std::list< std::pair<int, int>> PlayingField::getCoinsList() {
	std::list<std::pair<int, int>> returnList = this->getPlayersCoins();
	std::list<std::pair<int, int>> pcCoins = this->getPCCoins();
	std::list<std::pair<int, int>>::iterator i = pcCoins.begin();
	
	//put both lists together
	for (i; i != pcCoins.end(); i++) {
		returnList.push_back(*i);
	}
	return returnList;
}

bool PlayingField::setCoinInTable(int xValue, bool pc) {

	//if line is empty
	if (this->getFieldState(xValue, yMax) == State::FREE) {
		if (pc) {
			this->setFieldState(xValue, yMax, State::PC);
			this->addPairToList(xValue, yMax, true);
		}
		if (!pc) {
			this->setFieldState(xValue, yMax, State::PLAYER);
			this->addPairToList(xValue, yMax, false);
		}
		return true;
	}

	//if lowest place of the line is not empty
	if (this->getFieldState(xValue, yMax) != State::FREE) {
		
		for (int y = 0; y <= yMax; y++) {

			if (this->getFieldState(xValue, y) != State::FREE) {

				if (pc) {
					this->setFieldState(xValue, y - 1, State::PC);
					this->addPairToList(xValue, y - 1, true);

					if (y - 1 == 0) {
						this->addLineToList(xValue);
					}
					return true;
				}

				if (!pc) {
					this->setFieldState(xValue, y - 1, State::PLAYER);
					this->addPairToList(xValue, y - 1, false);

					if (y - 1 == 0) {
						this->addLineToList(xValue);
					}
					return true;
				}
			}
		}
	}

}