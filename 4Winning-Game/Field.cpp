#include "Field.hpp"

Field::Field() {

}

State Field::getState() {
	return myState;
}

void Field::setState(State state) {
	myState = state;
}