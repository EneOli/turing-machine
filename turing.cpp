#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>
#include <algorithm>

#include <chrono>
#include <thread>

#include "turing_tape.hpp"
#include "turing_move.hpp"
#include "turing_transition.hpp"
#include "turing_state.hpp"
#include "turing_machine.hpp"

#define BLANK_SYMBOL '0'




void runTuring() {

	// process turing transitions
	std::vector<TuringTransition*> transitions;

	// currentStateIdentifier,tapeValue,nextStateIdentifier,turingOutput,move

	// Busy Beaver

	/*transitions.push_back(new TuringTransition('A', '0', 'B', '1', RIGHT));
	transitions.push_back(new TuringTransition('A', '1', 'C', '1', LEFT));
	transitions.push_back(new TuringTransition('B', '0', 'C', '1', RIGHT));
	transitions.push_back(new TuringTransition('B', '1', 'B', '1', RIGHT));
	transitions.push_back(new TuringTransition('C', '0', 'D', '1', RIGHT));
	transitions.push_back(new TuringTransition('C', '1', 'E', '0', LEFT));
	transitions.push_back(new TuringTransition('D', '0', 'A', '1', LEFT));
	transitions.push_back(new TuringTransition('D', '1', 'D', '1', LEFT));
	transitions.push_back(new TuringTransition('E', '0', 'H', '0', STAY));
	transitions.push_back(new TuringTransition('E', '1', 'A', '0', LEFT));*/

	transitions.push_back(new TuringTransition('A', '0', 'B', '1', RIGHT));
	transitions.push_back(new TuringTransition('A', '1', 'C', '1', LEFT));
	transitions.push_back(new TuringTransition('B', '0', 'A', '1', LEFT));
	transitions.push_back(new TuringTransition('B', '1', 'B', '1', RIGHT));
	transitions.push_back(new TuringTransition('C', '0', 'B', '1', LEFT));
	transitions.push_back(new TuringTransition('C', '1', 'S', '1', STAY));

	// add transittions

	TuringMachine machine(BLANK_SYMBOL);

	machine.initialize(transitions, "", 'A'); 

	using namespace std::chrono_literals;

	while(true) {
	    machine.printTape();
		machine.step();

		std::this_thread::sleep_for(2000ms);
	}


}

int main() {

	std::cout << "Turing Machine" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	runTuring();
}