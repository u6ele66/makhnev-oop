#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const vector <pair<string, string>> HTML_ENTITIES =
{ {
	{"\"", "&quot;"},
	{"'", "&apos;"},
	{"<", "&lt;"},
	{">", "&gt;"},
	{"&", "&amp;"}
} };

string ReadHtml(istream& inputStream);
string ReplaceEntity(string& htmlCode, const string& charRepresentation, const string& htmlEntity);
string HtmlDecode(string& htmlCode);