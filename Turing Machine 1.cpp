// Lucas Levesque
// CS 4301
// Turing Machine

#include <turing.h>

using namespace std;
  
Turing::Turing()
{
  name = "Lucas Levesque";
  labNumber = 10;
  description = "{(x=, x=y) | x is in {0,1}* and\n";
  description += "             y = 2's complement of x}";

}

void Turing::initializeMachine()
{
  /*
   *-------------------------------------------------------next state
   *----------------------------------------------------------move  |
   *-------------------------------------------write character   |  | 
   *---------------------------------------read character    |   |  |
   *------------------------current state               |    |   |  |   */
  machine.insert(pair<uint, TableEntry>(1, TableEntry(' ', ' ',  1, 1)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('1', ' ',  1, 2)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('0', ' ',  1, 4)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('*', '*',  1, 6)));
  
  machine.insert(pair<uint, TableEntry>(2, TableEntry('0', '0',  1, 2)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('1', '1',  1, 2)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('*', '*',  1, 2)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry(' ', '0', -1, 3)));
  
  machine.insert(pair<uint, TableEntry>(3, TableEntry('0', '0', -1, 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('1', '1', -1, 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('*', '*', -1, 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry(' ', '1',  1, 1)));
  
  machine.insert(pair<uint, TableEntry>(4, TableEntry('0', '0',  1, 4)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('1', '1',  1, 4)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('*', '*',  1, 4)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry(' ', '1', -1, 5)));
  
  machine.insert(pair<uint, TableEntry>(5, TableEntry('0', '0', -1, 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('1', '1', -1, 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('*', '*', -1, 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry(' ', '0',  1, 1)));
  
  machine.insert(pair<uint, TableEntry>(6, TableEntry('0', '0',  1, 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('1', '1',  1, 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry(' ', ' ', -1, 7)));
  
  machine.insert(pair<uint, TableEntry>(7, TableEntry('1', '0', -1, 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('0', '1',  0, 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('*', '*',  0, 0)));

}