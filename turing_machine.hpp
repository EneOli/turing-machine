#ifndef __TURING_MACHINE__
#define __TURING_MACHINE__

#include <iostream>

#include "turing_state.hpp"
#include "turing_tape.hpp"
#include "turing_move.hpp"

class TuringMachine {

    private:

        TuringTape tape; // tape the turing machine uses

        long tapePosition = 0; // current position on the tape
        
        std::map<char, TuringState*> identifierStateMapping; // mapping between state identifier and actual Turing State

        TuringState* currentState; // current state of the turing machine
    
    public:

        TuringMachine(char blankSymbol): tape(blankSymbol) {
        }

        void step() {

            char tapeValue = this->tape.get(this->tapePosition);
            auto action = this->currentState->getAction(tapeValue);

            char newStateIdentifier = std::get<0>(action);
            char newTapeValue = std::get<1>(action);
            TuringMove move = std::get<2>(action);

            this->tape.set(this->tapePosition, newTapeValue);

            switch (move)
            {
                case LEFT: {
                    (this->tapePosition)--;
                    break;
                }
                case RIGHT: {
                    (this->tapePosition)++;
                }
                case STAY:
                default:
                    break;
            }

            this->currentState = this->identifierStateMapping[newStateIdentifier];
        }

        void initialize(std::vector<TuringTransition*> &transitions, const char* tapeInput, const char initialStateIdentifier) {

            this->tape.load(tapeInput);

            for (TuringTransition* transition : transitions) {
                char currentState = transition->getCurrentStateIdentifier();

                char nextState = transition->getNextStateIdentifier();

                char tapeValue = transition->getTapeValue();

                char output = transition->getTuringOutput();

                TuringMove move = transition->getMove();

                TuringState* state;
                if (!this->identifierStateMapping.count(currentState)) {
                    state = new TuringState(currentState);
                    this->identifierStateMapping[currentState] = state;
                } else {
                    state = this->identifierStateMapping[currentState];
                }

                state->addAction(tapeValue, std::make_tuple(nextState, output, move));
            }

            this->currentState = this->identifierStateMapping[initialStateIdentifier];
        }

        void printTape() {

            const long leftestIndex = std::min(this->tape.getLeftestIndex(), this->tapePosition);
            const long rightestIndex = std::max(this->tape.getRightestIndex(), this->tapePosition);

            for (long i = leftestIndex; i <= rightestIndex; i++) {
                std::cout << this->tape.get(i);
            }
            std::cout << std::endl;

            for (long i = this->tape.getLeftestIndex(); i < this->tapePosition; i++) {
                std::cout << ' ';
            }
            std::cout << this->currentState->getIdentifier() << std::endl;
        }
};

#endif