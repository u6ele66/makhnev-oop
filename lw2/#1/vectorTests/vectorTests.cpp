#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../vector/source.h"

TEST_CASE("Empty vector")
{
	vector<float> vect;
	MultMaxDivMin(vect);
	CHECK(vect.empty());
}

TEST_CASE("Single element in vector")
{
	vector<float> vectTest = { -11.11 };
	vector<float> vectRes = { -11.11 };
	MultMaxDivMin(vectTest);
	CHECK(vectTest == vectRes);
}

TEST_CASE("Correct vector")
{
	vector<float> vectTest = { -1, -2, -4 };
	vector<float> vectRes = { -0.25, -0.5, -1 };
	MultMaxDivMin(vectTest);
	CHECK(vectTest == vectRes);
}

TEST_CASE("Sort some vect")
{
	vector<float> vectTest = { -1, -5, 13, -6, -12 };
	vector<float> vectRes = { -12, -6, -5, -1, 13 };
	SortVector(vectTest);
	CHECK(vectTest == vectRes);
}

TEST_CASE("Divide by zero")
{
	vector<float> vectTest = { 2, 1, 0 };
	vector<float> vectRes = { 2, 1, 0 };
	MultMaxDivMin(vectTest);
	CHECK(vectTest == vectRes);
}