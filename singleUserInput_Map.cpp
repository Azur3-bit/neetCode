// singleUserInput_Map.cpp

//  Todo -  (done)   Input of n values using A Funtion - Maps
// ?        (done)  User Input - Maps

#include <iostream>
#include <map>
using namespace std;
// Classes
// Functions

// Inputing N Values using a Funtion

map<string, int> Input(map<string, int> &Map)
{

    int n;
    cout << "enter no. of Values Which has to be entered : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string S;
        int N;
        cout << "Enter String : ";
        cin >> S;
        cout << "Enter number : ";
        cin >> N;

        Map.insert(pair<string, int>(S, N));
    }
    return Map;
}
int main()
{
    // Main Code Function

    map<string, int> Trash;

    // Devleoper Inputs

    Trash["First"] = 1;
    Trash["Second"] = 2;
    Trash["Third"] = 3;
    Trash["Forth"] = 4;

    // Input(Trash);

    cout << "\t___ Start of Maps ___" << endl;

    // map<string,int> :: iterator it;
    // for(it = Trash.begin();it!=Trash.end();it++){
    //     cout << (*it).first << " \t" << (*it).second << endl;
    // }
    // cout << "\t.. End of Maps .."<<endl<<endl;

    cout << "Value"
         << "\t"
         << "Key" << endl;
    cout << "-----"
         << "\t"
         << "-----" << endl;

    for (auto i : Trash)
    {
        cout << i.first << " \t" << i.second << endl;
    }

    cout << "\t___ End of Maps ___" << endl;

    return 0;
}