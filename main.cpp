/*
* Ethan Dang
* 2326380
* edang@chapman.edu
* CPSC 350-02
* Assignment 1
* Main class that runs file processer and asks user for path to text files
*/
#include <iostream>
#include <string>
#include "Assign1.h"

using namespace std;

int main(int argc, char** argv)
{
  Assign1 foo;
  if (argc == 2) // checks if command line argument is given, if not then as for path
  {
    foo.run(argv[1]);
  }
  while (true)
  {
    cout << "Enter path to text file (Enter 0 to exit)" << endl;
    string file = "";
    cin >> file;
    if (file == "0")
    {
      return 0;
    }
    foo.run(file);
  }
}
