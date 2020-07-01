#include <iostream>
#include <fstream>
#include "copyFile.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Проверка корректности аргументов комендной строки
	if (argc != 3)
	{
		cout << "Invalid arguments count \n";
		cout << "Usage: copyFile.exe <input file name> <output file name> \n";
		return 1;
	}

	// Открытие и проверка на успешность открытия входного фпйла
	ifstream input;
	input.open(argv[1]);
	if (!input.is_open())
	{
		cout << "Failed to open" << argv[1] << " for reading \n";
	}

	//Открытие и проверка на успешность открытия выходного файла
	ofstream output;
	output.open(argv[2]);
	if (!output.is_open())
	{
		cout << "Failed to open" << argv[2] << " for writing \n";
		return 1;
	}

	char ch;
	while (input.get(ch))
	{
		if (!output.put(ch))
		{
			break;
		}
	}

	if (!output.flush())
	{
		cout << "Failed to write data to output file \n";
		return 1;
	}

	cout << "Successful copying" << "\n";

	return 0;
}