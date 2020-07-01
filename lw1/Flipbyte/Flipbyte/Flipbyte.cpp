#include <optional>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Args
{
	string inputFileName;
	string outputFileName;
};

//	Функция получения данных из аргументов командной строки
optional<Args> GetArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid number of arguments\n";
		cout << "Usage: Flipbyte.exe <input file> <output file>\n";
		return nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}

//	Проверяет, является ли строка числом
bool isNumber(const string& line)
{
	for (int i = 0; i < line.size(); i++)
	{
		if (!isdigit(line[i]))
		{
			cout << "Entered string must be an integer number bigger than 0 and less than 255\n";
			return false;
		}
	}

	return true;
}

//	Разворачивает биты в числе, с установленной base(256 для 8 бит)
bool Flipper(int number, int base, ostream& output)
{
	unsigned int res = 0;
	while (number != 0)
	{
		res += (number & 1) * (base >>= 1);
		number >>= 1;
	}

	if (output << res)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FlipByte(const string& inputFileName, const string& outputFileName)
{
	//	Инициализация входного потока
	ifstream inputFile;
	inputFile.open(inputFileName);
	if (!inputFile.is_open())
	{
		cout << "Failed to open " << inputFileName << " for reading\n";
		return false;
	}

	//	Инициализация выходного потока
	ofstream outputFile;
	outputFile.open(outputFileName);
	if (!outputFile.is_open())
	{
		cout << "Failed to open " << outputFileName << " for writing\n";
		return false;
	}

	string line;
	int number;

	if (inputFile >> line)
	{
		if (isNumber(line))
		{
			number = atoi(line.c_str());
			if (number >= 0 && number <= 255)
			{
				if (!Flipper(number, 256, outputFile))
				{
					cout << "Failed to flip byte\n";
					return false;
				}
			}
			else
			{
				cout << "Number must be less than 255 and bigger than 0\n";
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (line.empty())
		{
			cout << "Line is empty, please write a number\n";
			return false;
		}
	}

	//	Проверка состояния входного потока
	if (inputFile.bad())
	{
		cout << "Failed to read data from input file\n";
		return false;
	}

	//	Проверка состояния выходного потока
	if (!outputFile.flush())
	{
		cout << "Failed to write data to output file\n";
		return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	//	Получение данных из аргументов командной строки
	auto args = GetArgs(argc, argv);
	if (args == nullopt)
	{
		return 1;
	}

	if (FlipByte(args->inputFileName, args->outputFileName))
	{
		return 0;
	}
	else
	{
		return 1;
	}

	return 0;
}