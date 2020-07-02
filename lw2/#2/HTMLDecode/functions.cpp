#include "Decode.h"

string ReadHtml(istream& inputStream)
{
	string htmlCode;
	getline(inputStream, htmlCode);
	return htmlCode;
}

string ReplaceEntity(string& htmlCode, const string& charRepresentation, const string& htmlEntity)
{
	string result = "";
	if (htmlCode.empty())
	{
		return result;
	}
	size_t pos = 0;
	size_t entityPos = 0;
	while (entityPos != string::npos)
	{
		entityPos = htmlCode.find(htmlEntity, pos);
		if (entityPos != string::npos)
		{
			result.append(htmlCode, pos, entityPos - pos);
			pos = entityPos + htmlEntity.size();
			result.append(charRepresentation);
		}
		else
		{
			result.append(htmlCode, pos, htmlCode.size());
			break;
		}
	}
	return result;
}

string HtmlDecode(string& htmlCode)
{
	string decoded = htmlCode;
	for (auto entity : HTML_ENTITIES)
	{
		decoded = ReplaceEntity(decoded, entity.first, entity.second);
	}
	return decoded;
}