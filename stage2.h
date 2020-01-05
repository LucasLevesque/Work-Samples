// ------------Include Files-----------

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctime>
#include<iomanip>
#include<cstdio>
#include<cctype>
#include<sstream>
#include<cwctype>
#include<ios>
#include<stack>

using namespace std;

// ------------Global Variables-----------

const int MAX_SYMBOL_TABLE_SIZE = 256;
enum storeType {INTEGER, BOOLEAN, PROG_NAME, UNKNOWN};
enum allocation {YES,NO};
enum modes {VARIABLE, CONSTANT};
int lineNum = 1;
struct entry //define symbol table entry format
{
	string internalName;
	string externalName;
	storeType dataType;
	modes mode;
	string value;
	allocation alloc;
	int units;
};
vector<entry>symbolTable;
ifstream sourceFile;
ofstream listingFile,objectFile;
string token;
char charac;
const char END_OF_FILE = '$'; // arbitrary choice
bool isBegining = true;
bool isComment = false;
int integerCount = 0;
int booleanCount = 0;
int symbolCounter = 0;
int programCount = 0;
int tempCount = -1;
int maxTemp = -1;
int labelCount = -1;
int BeginCounter = 0;
stack<string> operatorStack;
stack<string> operandStack;
string contentsOfA;

// ------------Prototypes-----------

void CreateListingHeader();
void Parser();
void CreateListingTrailer(int);
void PrintSymbolTable();
void Prog();
void ProgStmt();
void Consts();
void Vars();
void BeginEndStmt();
void ConstStmts();
void VarStmts();
string Ids();
void Insert(string,storeType,modes,string,allocation,int);
storeType WhichType(string);
string WhichValue(string);
string NextToken();
char NextChar();
bool isInteger(string);
bool isNonKeyID(string);
string GenInternalName(storeType);
void PushOperator(string);
void PushOperand(string);
string PopOperator();
string PopOperand();
void FreeTemp();
string GetTemp();
void EmitAdditionCode(string, string);
void EmitSubractionCode(string, string);
void EmitDivisionCode(string, string);
void EmitMultiplicationCode(string, string);
void EmitModCode(string, string);
void EmitAssignCode(string, string);
void EmitAndCode(string, string);
void EmitOrCode(string, string);
void EmitEqualsCode(string, string);
void EmitNotEqualsCode(string, string);
void EmitLessThanCode(string, string);
void EmitGreaterThanCode(string, string);
void EmitGreaterThanEqualCode(string, string);
void EmitLessThanEqualCode(string, string);
void EmitNotCode(string);
void EmitReadCode(string);
void EmitWriteCode(string);
void EmitEndCode();
void EmitBeginCode();
void Code(string, string, string);
void ExecStmts();
void ExecStmt();
void AssignStmt();
void ReadStmt();
void ReadList();
void WriteStmt();
void WriteList();
void Express();
void Expresses();
void Term();
void Terms();
void Factor();
void Factors();
void Part();
void RelOp();
void AddLevelOp();
void MultLevelOp();
void IfStmt();
void ElsePt();
void WhileStmt();
void RepeatStmt();
void NullStmt();
void EmitThenCode(string);
void EmitElseCode(string);
void EmitPostIfCode(string);
void EmitWhileCode();
void EmitDoCode(string);
void EmitPostWhileCode(string, string);
void EmitRepeatCode();
void EmitUntilCode(string, string);
string printAlloc(int);
string printMode(int);
string printType(int);
int getIndex(string);
bool exists(string);
string getLabel();
