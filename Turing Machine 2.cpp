// Lucas Levesque
// CS 4301
// Turing Machine 2

#include <turing.h>

using namespace std;
  
Turing::Turing()
{
  name = "Lucas Levesque";
  labNumber = 9;
  description = "{(x=, x=a^ib^jc^k) | x is in {a,b,c}*,\n";
  description += "                     i = # of a's in x,\n";
  description += "                     j = # of b's in x, and\n";
  description += "                     k = # of c's in x}";
}
 
void Turing::initializeMachine()
{
  /*
   *-------------------------------------------------------next state
   *----------------------------------------------------------move  |
   *-------------------------------------------write character   |  | 
   *---------------------------------------read character    |   |  |
   *------------------------current state               |    |   |  |   */
  machine.insert(pair<uint, TableEntry>(1, TableEntry('=', '=',  0, 0)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry(' ', ' ',  1, 1)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('a', ' ',  1, 2)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('b', ' ',  1, 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('c', ' ',  1, 11)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('a', 'a',  1, 2)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('b', 'b',  1, 2)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('c', 'c',  1, 2)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('=', '=',  1, 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('a', 'a',  1, 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('b', 'a',  1, 4)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('c', 'a',  1, 5)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry(' ', 'a', -1, 6)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 'b',  1, 4)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('c', 'b',  1, 5)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry(' ', 'b', -1, 6)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('c', 'c',  1, 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry(' ', 'c', -1, 6)));
  
  machine.insert(pair<uint, TableEntry>(6, TableEntry('a', 'a', -1, 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('b', 'b', -1, 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('c', 'c', -1, 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('=', '=', -1, 6)));
  
  machine.insert(pair<uint, TableEntry>(6, TableEntry(' ', 'a',  1, 1)));
  
  machine.insert(pair<uint, TableEntry>(7, TableEntry('a', 'a',  1, 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('b', 'b',  1, 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('c', 'c',  1, 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('=', '=',  1, 8)));
  machine.insert(pair<uint, TableEntry>(8, TableEntry('a', 'a',  1, 8)));
  machine.insert(pair<uint, TableEntry>(8, TableEntry('b', 'b',  1, 8)));
  machine.insert(pair<uint, TableEntry>(8, TableEntry('c', 'b',  1, 9)));
  machine.insert(pair<uint, TableEntry>(8, TableEntry(' ', 'b', -1, 10)));
  machine.insert(pair<uint, TableEntry>(9, TableEntry('c', 'c',  1, 9)));
  machine.insert(pair<uint, TableEntry>(9, TableEntry(' ', 'c', -1, 10)));
  
  machine.insert(pair<uint, TableEntry>(10, TableEntry('a', 'a', -1, 10)));
  machine.insert(pair<uint, TableEntry>(10, TableEntry('b', 'b', -1, 10)));
  machine.insert(pair<uint, TableEntry>(10, TableEntry('c', 'c', -1, 10)));
  machine.insert(pair<uint, TableEntry>(10, TableEntry('=', '=', -1, 10)));
  
  machine.insert(pair<uint, TableEntry>(10, TableEntry(' ', 'b',  1, 1)));
  
  machine.insert(pair<uint, TableEntry>(11, TableEntry('a', 'a',  1, 11)));
  machine.insert(pair<uint, TableEntry>(11, TableEntry('b', 'b',  1, 11)));
  machine.insert(pair<uint, TableEntry>(11, TableEntry('c', 'c',  1, 11)));
  machine.insert(pair<uint, TableEntry>(11, TableEntry('=', '=',  1, 12)));
  machine.insert(pair<uint, TableEntry>(12, TableEntry('a', 'a',  1, 12)));
  machine.insert(pair<uint, TableEntry>(12, TableEntry('b', 'b',  1, 12)));
  machine.insert(pair<uint, TableEntry>(12, TableEntry('c', 'c',  1, 12)));
  machine.insert(pair<uint, TableEntry>(12, TableEntry(' ', 'c', -1, 13)));
  
  machine.insert(pair<uint, TableEntry>(13, TableEntry('a', 'a', -1, 13)));
  machine.insert(pair<uint, TableEntry>(13, TableEntry('b', 'b', -1, 13)));
  machine.insert(pair<uint, TableEntry>(13, TableEntry('c', 'c', -1, 13)));
  machine.insert(pair<uint, TableEntry>(13, TableEntry('=', '=', -1, 13)));
  
  machine.insert(pair<uint, TableEntry>(13, TableEntry(' ', 'c',  1, 1)));
}