#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <Windows.h>

using namespace std;

const string DICTIONARY_FILENAME = "Dictionary.txt";
const string SAVE_ALERT = "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";
const string EXIT_WITHOUT_SAVING_MESSAGE = "Изменения не сохраненены. До свидания.\n";
const string NO_CHANGES_EXIT_MESSAGE = "До свидания!\n";
const string SUCCESSFUL_SAVING_MESSAGE = "Изменения сохранены. До свидания.\n";
const string AGREEMENT_MESSAGE = "y";

void ConsoleInit();
void ReadDictionary(map<string, string>& _dictionary);
void RunTranslator(map <string, string>& _dictionary);
void SaveChanges(map<string, string> _dictionary);
void SaveTranslation(map <string, string>& _dictionary, const string& word, const string& translation);