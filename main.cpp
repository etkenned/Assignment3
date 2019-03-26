#include <iostream>
#include <fstream>
#include "Genstack.h"
using namespace std;

bool CheckDelimiters()
{
  string line = "";
  int lineNum = 1;
  fstream inputFile(fileName);
  if(inputFile.is_open())
  {
    while(getline(inputFile,line))
    {
      for(int i = 0; i < line.length()-1; i++)
      {
          if(line[i] == '(' || line[i] == '[' || line[i] == '{')
          {
            array.push(line[i]);
          }
          else if(line[i] == ')' || line[i] == ']' || line[i] == '}')
          {
            T temp = array.pop();
            if(temp != line[i])
            {
              cout << "Line " << lineNum << ": expected " << "PLACE HOLDER" << " and found " << line[i] << endl; 
              //alert the user to the location of the problem
              return false;
            }
          }
      }
    }
    if(array.isEmpty())
    {
      cout << "Delimiter syntax is correct" << endl;
      return true;
    }
    else
    {
      
    }
    
  }
}


int main(int argc, char** argv)
{
  string fileName = "";

  if(argc > 1) // checks for user input of file name
  {
    fileName = argv[1];

  }
  fstream inputFile(fileName);
}
