
#ifndef GAME_XBOARD_HPP_
#define GAME_XBOARD_HPP_

#include <iostream>
#include <string>

namespace bitchess {


class XBoardCtrl {
public:
	
	XBoardCtrl( std::istream in, std::ostream out );

	XBoardCtrl() :
			XBoardCtrl(std::cin, std::cout) {
	}


	void poll();


	void parse_command( std::string commandstr );
};

}

#endif
