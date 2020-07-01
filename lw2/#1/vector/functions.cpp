#include "source.h"

vector<float> GetVector(istream& stream)
{
	cout << ENTRY_MESSAGE;
	string numbersSequenceString;
	getline(stream, numbersSequenceString);
	istringstream strNumbers(numbersSequenceString);
	string number;
	vector<float> numbersVect;
	while (strNumbers >> number)
	{
		numbersVect.push_back((float)stod(number));
	}
	return numbersVect;
}

void MultMaxDivMin(vector<float>& anyVect)
{
	if (!anyVect.empty())
	{
		float minElement = *min_element(anyVect.begin(), anyVect.end());
		float maxElement = *max_element(anyVect.begin(), anyVect.end());
		for (size_t i = 0; i < anyVect.size(); i++)
		{
			if (minElement != 0)
			{
				anyVect[i] = anyVect[i] * maxElement / minElement;
			}
			// Если минимальный элемент равен 0, то не изменяю.
		}
	}
}

void SortVector(vector<float>& anyVect)
{
	sort(anyVect.begin(), anyVect.end());
}

void PrintVector(vector<float>& anyVect)
{
	for (float item : anyVect)
	{
		cout << item << ' ';
	}
	cout << '\n';
}