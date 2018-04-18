#pragma once
#include "State.hpp"

class Field {

	private:
		State myState;

	public:
		Field();
		State getState();
		void setState(State state);
};