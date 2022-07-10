#ifndef __TURING_TRANSITION__
#define __TURING_TRANSITION__

#include "turing_move.hpp"

/**
 * @brief This object represents a condition under wich the turing machine will change it's state /
 *        write something on the tape / move it's head.
 * 
 */
class TuringTransition  {

	private:
		char currentStateIdentifier; // state the machine should have for this transition to apply

        char tapeValue; // value of current tape position this transition expects

		char nextStateIdentifier; // next state the machine will take on
		
        char turingOutput; // output this transition will write on the tape at the current tape position

        TuringMove move; // direction of head movement

	public:
        /**
         * @brief Construct a new Turing Transition object
         * 
         * @param currentStateIdentifier // state the machine should have for this transition to apply
         * @param tapeValue // value of current tape position this transition expects
         * @param nextStateIdentifier // next state the machine will take on
         * @param turingOutput // output this transition will write on the tape at the current tape position
         * @param move // direction of head movement
         */
		TuringTransition(const char currentStateIdentifier,
                         const char tapeValue,
                         const char nextStateIdentifier,
                         const char turingOutput,
                         TuringMove move) : currentStateIdentifier(currentStateIdentifier),
                                            tapeValue(tapeValue),
                                            nextStateIdentifier(nextStateIdentifier),
                                            turingOutput(turingOutput),
                                            move(move) {
		}

        /**
         * @brief Get currentStateIdentifier
         * 
         * @return const char 
         */
	    const char getCurrentStateIdentifier() {
			return this->currentStateIdentifier;
		}

        /**
         * @brief Get nextStateIdentifier
         * 
         * @return const char 
         */
		const char getNextStateIdentifier() {
			return this->nextStateIdentifier;
		}

        /**
         * @brief Get turingOutput
         * 
         * @return const char 
         */
		const char getTuringOutput() {
			return this->turingOutput;
		}

        /**
         * @brief Get tapeValue
         * 
         * @return const char 
         */
		const char getTapeValue() {
			return this->tapeValue;
		}

        /**
         * @brief Get move
         * 
         * @return TuringMove 
         */
		TuringMove getMove() {
			return this->move;
		}
};

#endif