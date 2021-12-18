#include <iostream>
#include <string.h>
#include "board.h"
using namespace std;



int main(int argc, char* argv[]) {
   if (argv[1] == NULL) { 
      cout << "run with commandline parameters" << endl;
	  cout << "boardsize, [-all] , {[-f]/[-c]:tofile or toconsole}, [numofsolutionToPrint]" << endl;
	  return 0;
   }
   
   if(argv[2] == NULL) { 
      cout << "A Solution of " << argv[1] << "-Queen Problem \n" << endl;
      string s = argv[1];
      int i = stoi(s);
      Board b(i);
      b.findASolution();
      cout << b;
      return 0;
   }
   string s = argv[2];
   if (s == "-all") {
      //prints the total number of solutions
      //only shows the first 3 solutions
      cout << argv[1] << "-Queen Problem\n" << endl;
      string s = argv[1];
      int i = stoi(s);
      Board b(i);
      for (int i = 0; i < 3; i++) { 
         cout << "Solution:" << i + 1 << endl;
         b.findASolution();
         cout << b;
      }
      
   }

	return 0;
}