

#ifndef POSITION_PIECES_PIECES_HPP_
#define POSITION_PIECES_PIECES_HPP_

#include "util/bitboard.hpp"
#include "position/move.hpp"
#include "util/movelookup.hpp"

#include <vector>
#include <assert.h>

namespace bitchess {
namespace pieces {


class Piece {
public:
	/*
	 Gets all pseudolegal moves available to the Piece(s). These moves may result in
	  the king being in check, therefore they are not guaranteed to be legal and must be
	  tested.
	 */
	virtual std::vector<bitchess::Move> get_pseudolegal_moves(
			Bitboard all_occupancy, Bitboard own_occupancy,
			Bitboard opp_occupancy ) {
	}

protected:
	
	Piece() {
	}
	
	Piece( int initial_sq );
	bitchess::Bitboard occupancy;

};

//class PieceNone : public Piece {
//};
//
//class Rook : public Piece {
//};
//
//class Bishop : public Piece {
//};
//
//class Queen : public Piece {
//};
//

class SingleMovePiece: protected Piece {
public:
	
	std::vector<bitchess::Move> get_pseudolegal_moves(
			Bitboard all_occupancy, Bitboard own_occupancy,
			Bitboard opp_occupancy );

protected:
	SingleMovePiece() {
	}



	/*
	
	 
	 * Scans for the LS1B bit of the bitboard, gets its index and removes it, modifying
	 * moves_bb. Replaces the Move reference given with a new Move.
	 * @param king_loc board index of king location.
	 * @param moves_bb bitboard to scan from.
	 * @param move Reference of Move to modify, typically an array element
	 * @param is_capture whether the created Move should be a capture
	 */
	inline void __scan_moves__( short king_loc, Bitboard& moves_bb,
								bitchess::Move& move, bool is_capture ) {
		// scan and remove LS1B
		std::pair<short, Bitboard> result = moves_bb.bitscan_and_remove();
		int target_sq = result.first; // index of LS1B
		moves_bb = result.second; // bitboard resulting from bitscan and remove
		// create a new move at the given reference
		move = (bitchess::Move(king_loc, target_sq, is_capture,
							   get_piece_type()));
	}

	virtual inline bitchess::PieceType::PieceType get_piece_type() = 0;

	virtual inline bitchess::Bitboard get_moves_bitboard(short sq) = 0;

};

class King: public SingleMovePiece {
public:
	/**
	 * Creates a new King with a blank occupancy bitboard.
	 */
	King() {

	}

	/**
	 * Creates a new King with an initial occupancy bitboard.
	 * @param initial_occupancy
	 */
	King( Bitboard initial_occupancy ) {
		occupancy = Bitboard(initial_occupancy);
	}

	inline bitchess::PieceType::PieceType get_piece_type() {
		return bitchess::PieceType::KING;
	}

	inline bitchess::Bitboard get_moves_bitboard(short sq) {
		return bitchess::move_lookup(bitchess::PieceType::KING,sq);
	}
};

class Knight: public SingleMovePiece {
public:
	/**
	 * Creates a new Knight with a blank occupancy bitboard.
	 */
	Knight() {

	}

	/**
	 * Creates a new Knight with an initial occupancy bitboard.
	 * @param initial_occupancy
	 */
	Knight( Bitboard initial_occupancy ) {
		occupancy = Bitboard(initial_occupancy);
	}

	inline bitchess::PieceType::PieceType get_piece_type() {
		return bitchess::PieceType::KNIGHT;
	}

	inline bitchess::Bitboard get_moves_bitboard(short sq) {
		return bitchess::move_lookup(bitchess::PieceType::KNIGHT,sq);
	}

};

class Pawn: public Piece {
	//TODO: Separate into two more subclasses, BlackPawn and WhitePawn
public:
	virtual std::vector<bitchess::Move> get_pseudolegal_moves(
			Bitboard all_occupancy, Bitboard own_occupancy,
			Bitboard opp_occupancy );
	Pawn() {

	}
	Pawn( Bitboard initial_occupancy ) {
		occupancy = Bitboard(initial_occupancy);
	}
	Bitboard get_single_moves( Colour colour, Bitboard occupancy );
	Bitboard get_double_moves( Colour colour, Bitboard occupancy );
	Bitboard get_captures( Colour colour, Bitboard opp_occupancy );
	Bitboard get_promotions( Colour colour, Bitboard single_moves );

};

}

}

#endif 