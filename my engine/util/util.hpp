

#ifndef UTIL_UTIL_HPP_
#define UTIL_UTIL_HPP_

#include <string>
#include <array>

#include <iostream>

namespace bitchess {


enum Colour { WHITE, BLACK };
namespace PieceType {

enum PieceType { ROOK, KNIGHT, BISHOP, QUEEN, KING, PAWN, NO_PIECE };



}

inline std::ostream& operator<<(std::ostream& out, const PieceType::PieceType piece) {
	static std::array<std::string, 7> pieces = {{"R","N","B","Q","K", "p", "Empty"}};
	return out << pieces[piece];
}

inline std::string index_to_square(int index) {
	
	int div = (index/8);
	short rem = (index % 8)+97;
	return std::string(1,rem) + std::to_string(div + 1);
}

}


#endif /* UTIL_UTIL_HPP_ */
