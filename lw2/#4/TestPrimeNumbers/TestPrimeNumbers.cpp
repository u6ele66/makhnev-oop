#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../PrimeNumbers/PrimeNum.h"

TEST_CASE("Invalid count of arguments")
{
	int actual = ParseArguments(0, NULL);
	int excpected = NULL;
	CHECK(actual == excpected);
}

TEST_CASE("Correct arguments")
{
	char* agrv[] = { (char*)"hello", (char*)"14" };
	int actual = ParseArguments(2, agrv);
	int excpected = 14;
	CHECK(actual == excpected);
}

TEST_CASE("Incorrect bound")
{
	char* agrv[] = { (char*)"hello", (char*)"100000001" };
	int actual = ParseArguments(2, agrv);
	int excpected = NULL;
	CHECK(actual == excpected);
}

TEST_CASE("Generating set when upper bound is equal 50")
{
	set<int> excpected = { 2, 3, 5, 7, 11,
							13, 17, 19, 23,
							29, 31, 37, 41, 43, 47 };
	CHECK(GeneratePrimeNumbersSet(50) == excpected);
}