#ifndef __TURING_TAPE__
#define __TURING_TAPE__

#include <vector>
#include <cstring>

/**
 * TuringTape
 * 
 * @brief This is a turing tape. It allows to write on a tape using positive and negative index.
 *        If an index was not written, it will use the provided blank symbol and extend the tape with it.
 * 
 * @example
 *  Tape tape;
 *  tape.get(10); 
 *  tape.set(-11, 'A');
 * 
 */
class TuringTape {

	private:

        char blankSymbol; // Blank symbol the tape has

		std::vector<char> right; // Right side of tape. Holds element with index 0
		
        std::vector<char> left;  // Left side of tape

        /**
         * @brief assures the passed index can be accessed with vec. Fills with blank symbols if necessary
         * 
         * @param vec std::vector to check
         * @param index index to assure to access
         */
		void assureVectorIndex(std::vector<char> *vec, long index) {

			while (vec->size() < index + 1) {
				vec->push_back(this->blankSymbol);
			}
		}
	
        /**
        * @brief Obtains the right vector by looking at the passed position. if positive or zero: use right, else use left
        * 
        * @param position position to look at
        * @return std::vector<char>* 
        */
		std::vector<char>* getVectorFromPosition(long position) {

			bool useRight = (position >= 0);
			std::vector<char>* target = useRight ? &(this->right) : &(this->left);

			return target;
		}

        /**
        * @brief Returns index to work with right and left vectors
        * 
        * @param index index to gix
        * @return long 
        */
		long getFixedIndex(long index) {
			if (index < 0) {
				return -(index + 1);
			} else {
				return index;
			}
		}

	public:

        /**
         * @brief Construct a new Turing Tape object
         * 
         * @param blankSymbol blank symbol the tape uses
         */
        TuringTape(char blankSymbol) {
            this->blankSymbol = blankSymbol;
        }

        /**
         * @brief Returns the tape value on the passed position
         * 
         * @param position postition to look at
         * @return char tape character at passed position
         */
		char get(long position) {

			std::vector<char>* target = this->getVectorFromPosition(position);

			long index = this->getFixedIndex(position);

			this->assureVectorIndex(target, index);

			return target->at(index);
		}

        /**
         * @brief Writes the tape at the given position
         * 
         * @param position position to write at
         * @param c character to write
         */
		void set(long position, char c) {
			std::vector<char>* target = this->getVectorFromPosition(position);
			
			long index = this->getFixedIndex(position);

			this->assureVectorIndex(target, index);

			target->at(index) = c;
		}

        /**
         * @brief Loads data on the tape beginning at index 0
         * 
         * @param data data to load
         */
        void load(const char* data) {

			long bytes = std::strlen(data);
			for (long i = 0; i < bytes; i++) {
				this->set(i, data[i]);
			}
		}

        /**
         * @brief Returns rightest index that was written to
         * 
         * @return long 
         */
		long getRightestIndex() {
			long size = this->right.size();

			return size == 0 ? size : size - 1;
		}

        /**
         * @brief Returns leftest index that was written to
         * 
         * @return long 
         */
		long getLeftestIndex() {
			long size = this->left.size();

			return size == 0 ? size : -(size);
		}

};

#endif