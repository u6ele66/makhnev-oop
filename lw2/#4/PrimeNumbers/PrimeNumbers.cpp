#include "PrimeNum.h"

int main(int argc, char* argv[])
{
    unsigned int START_TIME = clock();

    setlocale(LC_ALL, "Russian");
    int upperBound = ParseArguments(argc, argv);
    if (upperBound == NULL)
    {
        return 1;
    }

    set<int> PrimeNumbers = GeneratePrimeNumbersSet(upperBound);

    unsigned int END_TIME = clock();

    cout << GENERATING_TIME << END_TIME - START_TIME << " ms.\n";

    cout << "Количество простых чисел в диапазоне [" << MIN_BOUND << ", " << MAX_BOUND << "] равно - " << PrimeNumbers.size() << '\n';


}