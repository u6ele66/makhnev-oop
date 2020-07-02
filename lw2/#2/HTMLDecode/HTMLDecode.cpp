#include "Decode.h"

int main()
{
    string htmlCode = ReadHtml(cin);
    cout << HtmlDecode(htmlCode) << '\n';
    return 0;
}