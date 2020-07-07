#pragma once

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

const int MAX_BOUND = 100000000;
const int MIN_BOUND = 1;
const int MIN_PRIME = 2;

const string INVALID_ARGC = "Ivalid arguments count!\nUsage: PrimeNumbers.exe <upperBound>\n";
const string INVALID_BOUND = "Invalid upper bound! It must be in [1, 100000000]\n";
const string GENERATING_TIME = "Время построения множества простых чисел : ";
int ParseArguments(int argc, char* argv[]);
set<int> GeneratePrimeNumbersSet(int upperBound);
void PrintSet(set<int> numbers);