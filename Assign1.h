/*
* Ethan Dang
* 2326380
* edang@chapman.edu
* CPSC 350-02
* Assignment 1
* Assign1 header class, defining all variables, constructors and methods
*/
#include <iostream>
#include <string>

using namespace std;

class Assign1
{
  private: // variables
    bool newFile;
    int sum;
    int sumS;
    int numStrings;
    int numBigrams;
    double mean;
    double variance;
    double stdDev;
    double probA;
    double probG;
    double probT;
    double probC;
    double probAA;
    double probAG;
    double probAT;
    double probAC;
    double probGA;
    double probGG;
    double probGT;
    double probGC;
    double probTA;
    double probTG;
    double probTT;
    double probTC;
    double probCA;
    double probCG;
    double probCT;
    double probCC;
    string total;

  public:
  // constructor
    Assign1();

  // method to run program (get stats and print to file)
    void run(string text);
    // String text represents name of text file

  // method to calculate the probablity of each nucleotide and nucleotide bigram
    void calcProbability();

  // method that generates DNA strings
    void genStrings();

  // method to calculate length using Gaussian distribution
    int calcLength();

  // method to write to file
    void writeFile(string text);
    // String text represents text to be added to file

  // method that prints stats to file
    void startFile();
};
