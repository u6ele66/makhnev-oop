#include "PrimeNum.h"

int ParseArguments(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << INVALID_ARGC;
		return NULL;
	}
	int upperBound = atoi(argv[1]);
	if (upperBound < MIN_BOUND || upperBound > MAX_BOUND)
	{
		cout << INVALID_BOUND;
		return NULL;
	}
	return upperBound;
}

vector<bool> EratosthenesSieve(int upperBound)
{
	vector<bool> PrimeNumbers(upperBound + 1, true);
	PrimeNumbers[0] = PrimeNumbers[1] = false;
	for (size_t i = MIN_PRIME; i * i < PrimeNumbers.size(); i++)
	{
		if (PrimeNumbers[i])
		{
			for (size_t j = i * i; j < PrimeNumbers.size(); j += i)
			{
				PrimeNumbers[j] = false;
			}
		}
	}
	return PrimeNumbers;
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	set<int> PrimeNumbersSet;
	vector<bool> PrimeNumbersVect = EratosthenesSieve(upperBound);
	for (size_t i = MIN_PRIME; i < PrimeNumbersVect.size(); i++)
	{
		if (PrimeNumbersVect[i])
		{
			PrimeNumbersSet.emplace(i);
		}
	}
	return PrimeNumbersSet;
}

void PrintSet(set<int> numbers)
{
	int count = 0;
	for (auto item : numbers)
	{
		if (count < 9)
		{
			cout << item << ' ';
			count++;
		}
		else
		{
			cout << item << '\n';
			count = 0;
		}
	}
	cout << '\n';
}