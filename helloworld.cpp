#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (int i = 0; i < msg.size(); i++)
    {
        cout << msg[i] << " ";
    }
    cout << endl;
}