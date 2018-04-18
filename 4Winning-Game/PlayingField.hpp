#pragma once
#include "Field.hpp"
#include <iostream>
#include <map>
#include <list>

class PlayingField {

	private:
		static const int height = 6;
		static const int length = 7;
		int xMax = length - 1;
		int yMax = height - 1;
		int pcKey = 0;
		int playersKey = 1;

		Field playingField[length][height];
		std::list<int> linesList;
		std::map<int, std::list<std::pair<int, int>>> coins;
		std::map<int, std::list<std::pair<int, int>>>::iterator it;

	public:
		PlayingField();
		~PlayingField();

		void initPlayingField();
		void showPlayingField();
		bool proofLine(int xLine);
		bool proofEnter(int xEnter);

		void addLineToList(int xEnter);
		void addPairToList(int x, int y, bool pc);
		State getFieldState(int xPos, int yPos);
		void setFieldState(int xPos, int yPos, State state);
		int getHeight();
		int getLength();
		int getXMax();
		int getYMax();
		std::map<int, std::list<std::pair<int, int>>> getCoins();
		std::list<std::pair<int, int>> getPlayersCoins();
		std::list<std::pair<int, int>> getPCCoins();
		std::list<std::pair<int, int>> getCoinsList();
		std::list<int> getLinesList();
};