#include <iostream>
#include <fstream>
#include "Genstack.h"
using namespace std;

int main(int argc, char** argv)
{
  string fileName = "";

  if(argc > 1) // checks for user input of file name
  {
    fileName = argv[1];

  }
  fstream inputFile(fileName);
}
