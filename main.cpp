#include <iostream>
#include <fstream>
#include "GenStack.h"
#include <string>
using namespace std;


bool CheckDelimiters( string fileName)
{
  GenStack<char> array = GenStack<char>();
  string line = "";
  int lineNum = 1;
  fstream inputFile(fileName);
  if(inputFile.is_open())
  {
    while(getline(inputFile,line)) // gets ever line in the file
    {
      for(int i = 0; i < line.length()-1; i++) //iterates through the char of the line
      {
          if(line[i] == '(' || line[i] == '[' || line[i] == '{') //checks for opening bracket
          {
            array.push(line[i]);
          }
          else if(line[i] == ')' || line[i] == ']' || line[i] == '}')//checks for closeing bracket
          {
            if(array.isEmpty())
            {
              cout << "Line " << lineNum << ": there is a " << line[i] << " with no open delimiter" << endl;
              return false;
            }
            else
            {
              char temp = array.pop();

              if(temp == '(' && line[i] != ')')
              {
                cout << "Line " << lineNum << ": expected )" << " and found " << line[i] << endl; //alert the user to the location of the problem
                return false;
              }
              else if(temp == '[' && line[i] != ']')
              {
                cout << "Line " << lineNum << ": expected ]" << " and found " << line[i] << endl; //alert the user to the location of the problem
                return false;
              }
              else if(temp == '{' && line[i] != '}')
              {
                cout << "Line " << lineNum << ": expected }" << " and found " << line[i] << endl; //alert the user to the location of the problem
                return false;
              }

            }
          }
      }
      lineNum++;
    }
    if(array.isEmpty())
    {
      cout << "Delimiter syntax is correct" << endl;
      return true;
    }
    else
    {
      cout << "Some delimiters were never matched" << endl;
      return false;
    }

  }
  else // if the file name does not work
  {
    cout << "Error in name of file" << endl;
    return true;
  }
  inputFile.close();
}

int main(int argc, char** argv)
{
  string fileName = "";

  if(argc > 1) // checks for user input of file name
  {
    fileName = argv[1];
  }
  string input = "";
  while(CheckDelimiters(fileName))
  {
    cout << "Would you like to analyze another file? (y) or (n)" << endl;
    cin >> input;
    if(input == "n")
    {
      break;
    }
    else if(input == "y")
    {
    }
    else
    {
      cout << "invalid input, ending program." << endl;
      break;
    }
  }
}
