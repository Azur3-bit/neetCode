#include <bits/stdc++.h>
using namespace std;
    // Classes
    // Functions
int main()
{
    // Main Code Function


    map<string ,int> LearningMap;

    LearningMap["Sunil"] = 98;
    LearningMap["Rahul"] = 100;
    LearningMap["Shyam"] = 90;


    // Creating an Iterator 

    map<string,int> :: iterator iter;

    // Going Through the Map 

    for(iter=LearningMap.begin();iter!=LearningMap.end();iter++){
        cout << (*iter).first << " " << (*iter).second << endl; 
    }

    cout << "Fininshed !" << endl;

    return 0;
}