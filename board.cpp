#include "board.h"
#include <vector>
#include <unordered_map>
using namespace std;

//================================= Variables
       int boardSize = 4;
       int maxNumber = 3;
       int board[15][15];
		 bool isPrintToFile = false;
      //================================= Constructor
      
      Board::Board(int i) {
         boardSize = i;
      }
      //================================= Methods
      int Board::getBoardSize() {
         return boardSize;
      }
      
      int Board::getQueenAtRow(int row) {
         for (int i = 0; i < getBoardSize(); i++) { 
            if (hasQueenAtPos(row,i)) {
               return i;
            }
         }
         return 0;
      }
      
	  bool Board::hasQueenAtPos(int row, int col) {
		   if (board[row][col] == 1) { 
		      return true;
		   }
		   return false;
		}
		
		void Board::putQueenAtPosition(int row, int col){
		      board[row][col] = 1;
		   }
		   
		bool Board::isDiagonalSafe(int posRow,int posCol) {
		  bool first = true;
		  int j = posCol;
		  for (int i = posRow; i > 0; i--) {
		     if (j == getBoardSize() - 1) break;
		     if (first) {
		      i--;
		      j++;
		     }
		     if (hasQueenAtPos(i,j)) return false;
		     first = false;
		     j++;
		  }
		  
		  j = posCol;
		  first = true;
		  for(int i = posRow; i >= 0; i--) {
		     if (j < 0) break;
		     if (first) {
		        j--;
		        i--;
		     }
		     if (hasQueenAtPos(i,j)) return false;
		     first = false;
		     j--;
		  }
		  return true;
		}
		
		bool Board::IsColumnSafe(int row,int col) { 
		   for (int i = 0; i < getBoardSize(); i++) { 
		      if (hasQueenAtPos(i,col)) { 
		         return false;
		      }
		   }
		   return true;
		}
		
		bool Board::isSafe(int row, int col){
		   if (IsColumnSafe(row,col) && isDiagonalSafe(row,col)) return true;
		   return false;
		}
		
		void Board::resetQueenAtRow(int row){
		  for (int i = 0; i < getBoardSize(); i++) { 
		     board[row][i] = 0;
		  }
		}
		void Board::findASolution() {
		   int row = 0;
		   int col = 0;
		   int count = 0;
		   int prevCol = -1;
		   while (row < getBoardSize()) {
		      if (IsColumnSafe(row,col) && isDiagonalSafe(row,col) && prevCol < col) { 
		         putQueenAtPosition(row,col);
		         row++;
		         col = 0;
		         prevCol = -1;
		      } else {
		         col++;
		      }
		      if (col == getBoardSize()) { 
		         resetQueenAtRow(row);
		         row--;
		         prevCol = -1;
		         prevCol = getQueenAtRow(row);
		         resetQueenAtRow(row);
		         col = 0;
		      }
		      count++;
		      if (count > 1000) {
		         break;
		      }
		   }
		 }
		
		void Board::findAllSolutions(bool isPrintToFile, int maxNumber){
		   
		}
		
		//======================================================== Operators
		ostream& operator<<(ostream& out, Board& b) {
		   for (int i = 0; i < b.getBoardSize(); i++) {
		      for (int j = 0; j < b.getBoardSize(); j++) {
		        if ((b.hasQueenAtPos(i,j))) {
		         out << "Q";
		         } else { 
		            out << "-";
		         }
		      }
		      out << endl;
		   }
		   out << endl;
		   return out;
		}