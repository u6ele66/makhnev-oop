#include "TVSet.h"
#include "RemoteControl.h"

using namespace std;

int main()
{
    CTVSet NewTV;
    Control Controller;
    Controller.Controller(NewTV, cin, cout);
    return 0;
}   