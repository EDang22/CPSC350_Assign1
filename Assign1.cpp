/*
* Ethan Dang
* 2326380
* edang@chapman.edu
* CPSC 350-02
* Assignment 1
* Assign1 implementation file containing all methods to process DNA strings and methods for output file
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include "Assign1.h"

using namespace std;

// constructor, sets variables and adds name to file
Assign1::Assign1()
{
  bool newFile = true; // if output file has been opened before
  int sum = 0;
  int sumS = 0; // sum of lengths squared (for variance)
  int numStrings = 0;
  int numBigrams = 0;
  double mean = 0.0;
  double variance = 0.0;
  double stdDev = 0.0;
  double probA = 0.0;
  double probG = 0.0;
  double probT = 0.0;
  double probC = 0.0;
  double probAA = 0.0;
  double probAG = 0.0;
  double probAT = 0.0;
  double probAC = 0.0;
  double probGA = 0.0;
  double probGG = 0.0;
  double probGT = 0.0;
  double probGC = 0.0;
  double probTA = 0.0;
  double probTG = 0.0;
  double probTT = 0.0;
  double probTC = 0.0;
  double probCA = 0.0;
  double probCG = 0.0;
  double probCT = 0.0;
  double probCC = 0.0;
  string total = ""; // all DNA strings added together, with "." to indicate end of line
  srand(time(0));
  writeFile("Ethan Dang\n2326380\nedang@chapman.edu\nCPSC 350-02\nAssignment 1\n"); // adds name and other info to file
}

// Run method, takes in file name and processes, adding results to output file
void Assign1::run(string text)
{
  string DNA = "";
  ifstream file(text);
  if (file)
  {
    while (getline(file, DNA)) // reads file line by line
    {
      ++numStrings;
      sum += DNA.length();
      sumS += DNA.length() * DNA.length();
      for_each(DNA.begin(), DNA.end(), [](char & c) // sets all characters in string to lower case
      {
        c = ::tolower(c);
      });
      total = total + DNA + "."; // indicates end of line
    }
  }
  else
  {
    cerr << "Error: File could not be opened" << endl;
    return;
  }
  mean = sum / numStrings;
  variance = (sumS / numStrings) - mean;
  stdDev = sqrt(variance);
  calcProbability();
  startFile();
  genStrings();
  cout << "Successfully processed file" << endl;
}

// calculates probability of all nucleotides and nucleotide bigrams
void Assign1::calcProbability()
{
  int numDots = 0; //number of periods found
  int numA = 0;
  int numG = 0;
  int numC = 0;
  int numT = 0;
  int numAA = 0;
  int numAG = 0;
  int numAT = 0;
  int numAC = 0;
  int numGA = 0;
  int numGG = 0;
  int numGT = 0;
  int numGC = 0;
  int numTA = 0;
  int numTG = 0;
  int numTT = 0;
  int numTC = 0;
  int numCA = 0;
  int numCG = 0;
  int numCT = 0;
  int numCC = 0;
  for (int i = 0; i < total.length(); ++i)
  {
    if (total[i] == 'a')
    {
      ++numA;
      if (i != total.length() - 1)
      {
        ++numBigrams;
        if (total[i + 1] == 'a')
        {
          ++numAA;
        }
        else if (total[i + 1] == 'g')
        {
          ++numAG;
        }
        else if (total[i + 1] == 't')
        {
          ++numAT;
        }
        else if (total[i + 1] == 'c')
        {
          ++numAC;
        }
      }
    }
    else if (total[i] == 'g')
    {
      ++numG;
      if (i != total.length() - 1)
      {
        ++numBigrams;
        if (total[i + 1] == 'a')
        {
          ++numGA;
        }
        else if (total[i + 1] == 'g')
        {
          ++numGG;
        }
        else if (total[i + 1] == 't')
        {
          ++numGT;
        }
        else if (total[i + 1] == 'c')
        {
          ++numGC;
        }
      }
    }
    else if (total[i] == 't')
    {
      ++numT;
      if (i != total.length() - 1)
      {
        ++numBigrams;
        if (total[i + 1] == 'a')
        {
          ++numTA;
        }
        else if (total[i + 1] == 'g')
        {
          ++numTG;
        }
        else if (total[i + 1] == 't')
        {
          ++numTT;
        }
        else if (total[i + 1] == 'c')
        {
          ++numTC;
        }
      }
    }
    else if (total[i] == 'c')
    {
      ++numC;
      if (i != total.length() - 1)
      {
        ++numBigrams;
        if (total[i + 1] == 'a')
        {
          ++numCA;
        }
        else if (total[i + 1] == 'g')
        {
          ++numCG;
        }
        else if (total[i + 1] == 't')
        {
          ++numCT;
        }
        else if (total[i + 1] == 'c')
        {
          ++numCC;
        }
      }
    }
    else
    {
      ++numDots;
    }
  }
  probA = (double) (numA) / (total.length() - numDots);
  probG = (double) (numG) / (total.length() - numDots);
  probT = (double) (numT) / (total.length() - numDots);
  probC = (double) (numC) / (total.length() - numDots);
  probAA = ((double) (numAA) / (numBigrams - numDots)) * 100;
  probAG = ((double) (numAG) / (numBigrams - numDots)) * 100;
  probAT = ((double) (numAT) / (numBigrams - numDots)) * 100;
  probAC = ((double) (numAC) / (numBigrams - numDots)) * 100;
  probGA = ((double) (numGA) / (numBigrams - numDots)) * 100;
  probGG = ((double) (numGG) / (numBigrams - numDots)) * 100;
  probGT = ((double) (numGT) / (numBigrams - numDots)) * 100;
  probGC = ((double) (numGC) / (numBigrams - numDots)) * 100;
  probTA = ((double) (numTA) / (numBigrams - numDots)) * 100;
  probTG = ((double) (numTG) / (numBigrams - numDots)) * 100;
  probTT = ((double) (numTT) / (numBigrams - numDots)) * 100;
  probTC = ((double) (numTC) / (numBigrams - numDots)) * 100;
  probCA = ((double) (numCA) / (numBigrams - numDots)) * 100;
  probCG = ((double) (numCG) / (numBigrams - numDots)) * 100;
  probCT = ((double) (numCT) / (numBigrams - numDots)) * 100;
  probCC = ((double) (numCC) / (numBigrams - numDots)) * 100;
}

// Generates 1000 strings and appends to output file
void Assign1::genStrings()
{
  for (int i = 0; i < 1000; ++i)
  {
    string genString = "";
    int length = calcLength();
    if (length <= 0) // to ensure 1000 strings will be made
    {
      --i;
      continue;
    }
    int maxA = round(probA * length);
    int maxG = round(probG * length);
    int maxT = round(probT * length);
    int maxC = round(probC * length);
    int numA = 0;
    int numG = 0;
    int numT = 0;
    int numC = 0;
    if (maxA + maxG + maxT + maxC < length) // to account for possibility of odd numbered length and rounding issues
    {
      ++maxA;
      ++maxG;
      ++maxT;
      ++maxC;
    }
    for (int j = 0; j < length; ++j)
    {
      // generates string based on length and probabilities
      int letter = (int) (rand() % (4));
      if (letter == 0)
      {
        if (numA != maxA)
        {
          genString += "A";
          ++numA;
        }
        else
        {
          --j;
          continue;
        }
      }
      else if (letter == 1)
      {
        if (numG != maxG)
        {
          genString += "G";
          ++numG;
        }
        else
        {
          --j;
          continue;
        }
      }
      else if (letter == 2)
      {
        if (numT != maxT)
        {
          genString += "T";
          ++numT;
        }
        else
        {
          --j;
          continue;
        }
      }
      else if (letter == 3)
      {
        if (numC != maxC)
        {
          genString += "C";
          ++numC;
        }
        else
        {
          --j;
          continue;
        }
      }
    }
    writeFile(genString);
  }
}

// Calculates the length using 2 random numbers, mean and standard deviation
int Assign1::calcLength()
{
  double a = ((double) rand() / (RAND_MAX));
  double b = ((double) rand() / (RAND_MAX));
  double c = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
  return (int) round(stdDev * c + mean);
}

// Takes string text and adds to output file
void Assign1::writeFile(string text)
{
  ofstream file;
  if (newFile)
  {
    newFile = false;
    file.open("EthanDang.out");
  }
  else
  {
    file.open("EthanDang.out", ofstream::out | ofstream::app);
  }
  if (file.is_open())
  {
    file << text << endl;
    file.close();
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
}

// Adds basic statistics of DNA strings to output file
void Assign1::startFile()
{
  stringstream stats;
  stats << "Sum: " << sum << "\n" << "Mean: " << mean << "\nVariance: " << variance << "\nStandard Deviation: " << stdDev;
  writeFile(stats.str());
  stringstream probabilities;
  probabilities << "\nFrequency of (in percentages):\nA: " << (probA * 100) <<
                         "\nG: " << (probG * 100) <<
                         "\nT: " << (probT * 100) <<
                         "\nC: " << (probC * 100) <<
                         "\nAA: " << probAA <<
                         "\nAG: " << probAG <<
                         "\nAT: " << probAT <<
                         "\nAC: " << probAC <<
                         "\nGA: " << probGA <<
                         "\nGG: " << probGG <<
                         "\nGT: " << probGT <<
                         "\nGC: " << probGC <<
                         "\nTA: " << probTA <<
                         "\nTG: " << probTG <<
                         "\nTT: " << probTT <<
                         "\nTC: " << probTC <<
                         "\nCA: " << probCA <<
                         "\nCG: " << probCG <<
                         "\nCT: " << probCT <<
                         "\nCC: " << probCC << endl;
  writeFile(probabilities.str());
}
