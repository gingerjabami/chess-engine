

#ifndef POSITION_POSITION_HPP_
#define POSITION_POSITION_HPP_

#include <map>
#include <array>
#include <vector>

namespace bitchess {


class Position {
public:
	/**
	 * Initialises an empty board.
	 */
	Position();
	
	Position(std::string FEN_string);


	std::map<Colour,std::map<PieceType, int>> get_piece_counts();

	/**
	 * Gets a list of legal moves that can be played by the side_to_move in this position.
	 * @param side_to_move Side currently on move.
	 * @return a vector of legal moves.
	 */
	std::vector<Move> get_all_legal_moves(Colour side_to_move);


private:
	/**
	 * Tests each moves for illegal check positions and removes any from the list that are illegal.
	 * @param side_to_move Side currently on move.
	 * @param move_list a vector of pseudolegal moves generated from this position. Will be modified
	 * with illegal moves removed.
	 * @return the modified move_list
	 */
	std::vector<Move> test_checks(Colour side_to_move, std::vector<Move> &move_list);

	std::map<Colour, std::map<PieceType,pieces::Piece>> map_pieces; //a map of the pieces
	std::array<*pieces::Piece,64> array_pieces; //an array representing board squares of the pieces.

};

}

#endif /* POSITION_POSITION_HPP_ */
