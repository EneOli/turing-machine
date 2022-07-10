#ifndef __TURING_STATE__
#define __TURING_STATE__

#include <map>
#include <stdexcept>

#include "turing_move.hpp"

typedef char TapeInput;

typedef std::tuple<char, char, TuringMove> OutputTapeMovePair;

/**
 * @brief State the turing machine can have
 * 
 */
class TuringState {

	private:
		
        char identifier; // char identifier of this state
		
        std::map<TapeInput, OutputTapeMovePair> actionMap; // mapping tape symbol <=> (new state, new tape symbol, move direction)
	
	public:

        /**
         * @brief Get the identifier char
         * 
         * @return char 
         */
        char getIdentifier() {
			return this->identifier;
		}

        /**
         * @brief Construct a new Turing State object
         * 
         * @param identifier char identifier of this state
         */
		TuringState(char identifier) : identifier(identifier) {
		}

        /**
         * @brief Adds an action the machine can apply if it is in this state 
         * 
         * @param input tape input
         * @param output OutputTapeMovePair
         */
		void addAction(TapeInput input, OutputTapeMovePair output) {
			if (actionMap.count(input)) {
				throw std::runtime_error("Error, action for this input already specified: " + input);
			} else {
				actionMap[input] = output;
			}
		}

        /**
         * @brief Get action from turing tape input
         * 
         * @param input turing tape input
         * @return OutputTapeMovePair 
         */
		OutputTapeMovePair getAction(TapeInput input) {

			if (!actionMap.count(input)) {
				throw std::runtime_error("Error, action for this input not specified: " + input);
			} else {
				return actionMap[input];
			}
        }

};

#endif