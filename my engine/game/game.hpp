
#ifndef GAME_GAME_HPP_
#define GAME_GAME_HPP_

#include "evaluation/search.hpp"
#include "position/position.hpp"
#include "position/move.hpp"

namespace bitchess {

class Game {
public:

	
	Game() :

			pfunc() {
	}


	
	Game( void (*polling_function)() ) :
			
			pfunc(&polling_function) {
	}


	Move get_next_move();

private:
	
	void (*pfunc)();


	Position current_position;

	Search searcher;

};

}

#endif 
