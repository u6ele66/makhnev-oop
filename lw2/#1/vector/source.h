#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <iomanip>

using namespace std;

const string ENTRY_MESSAGE = "Enter numbers separated by spaces: ";

vector<float> GetVector(istream& inputStream);
void MultMaxDivMin(vector<float>& anyVect);
void SortVector(vector<float>& anyVect);
void PrintVector(vector<float>& anyVect);