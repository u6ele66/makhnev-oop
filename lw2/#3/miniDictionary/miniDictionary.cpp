#include "Dictionary.h"

int main()
{
	ConsoleInit();
	map <string, string> dictionary;
	ReadDictionary(dictionary);
	RunTranslator(dictionary);
}