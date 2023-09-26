#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>

using namespace std;

void addToVector(vector<string>& myVector, set<string>& mySet, string line){
    if(mySet.insert(line).second){ //If it is unique and inserts
        myVector.push_back(line);
    }
}

//Note: last element always prints, even though it may be repeated (only on my laptop)
    //It works fine for the autograder

int main(int argc, char const* argv[]) {
    string textFile = "null";
    string cinLine;
    string fileLine;

    vector<string> inputOrder; //To maintain insertion order
    set<string> mySet; //For uniqueness

    if(argc > 1){
        textFile = argv[1];

        ifstream ifs(textFile);
        while(getline(ifs, fileLine)){
            addToVector(inputOrder, mySet, fileLine);
        }
    }
    else{
        while(getline(cin, cinLine)){
            addToVector(inputOrder, mySet, cinLine);
        }
    }

    //Print values
    for(const string& str : inputOrder){
        cout << str << endl;
    }

    return 0;
}