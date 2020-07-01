#include "source.h"

int main()
{
    vector<float> numbers = GetVector(cin);
    MultMaxDivMin(numbers);
    SortVector(numbers);
    PrintVector(numbers);
}
