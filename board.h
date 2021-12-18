#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

using namespace std;

class Board{
	
	private:
		int boardSize;
		int maxNumber;
		bool  isPrintToFile;
		int board[15][15];
		// add nqueen board as a member and other necessary members if any
		// if you store board as 1-d vector, you quarantee that no queen can place in the same row.
			

	public:
	   Board(int boardsize=4);
		int getBoardSize(); // return the board size
		bool hasQueenAtPos(int row, int col); // return true if there is a queen on the board[row][col]  
		void putQueenAtPosition(int row, int col);// put a queen on a specified position on the board
		int getQueenAtRow(int row); // Helper method that tells me where the queen in on a row
		bool isDiagonalSafe(int posRow,int posCol);// returns true if any queens can not attack diagonally on the board
		bool IsColumnSafe(int row,int col);//returns true if no queens exist on the column col
		bool isSafe(int row, int col) ; // return true if given position(row,col) is safe for diagonal and column attack
		void resetQueenAtRow(int row); // erase the queen from the given row
		// print the first available solution to the console
		void findASolution();
		// find the all solutions and print maxNumber of solutions either on console or to "solutions.txt" file based on the isPrintFile value
		void findAllSolutions(bool isPrintToFile=false, int maxNumber=3 ); 
		friend ostream& operator<<(ostream& out, Board& b);
};
// return the solution in printed format on ostream 
ostream& operator<<(ostream& out, Board & b);
#endif
