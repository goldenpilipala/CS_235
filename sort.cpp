#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void insertionSort(vector<string>& myVect){
    int size = myVect.size();

    for(int i=0; i<size; i++){
        int j = i-1;
        string item = myVect[i];

        while (j >= 0 && myVect[j] > item) {
            myVect[j + 1] = myVect[j];
            j--;
        }
        myVect[j + 1] = item;
    }
}

int main(int argc, char const* argv[]) {
    string textFile = "";
    string cinLine, fileLine;

    vector<string> toSort;

    if(argc > 1){
        textFile = argv[1];

        ifstream ifs(textFile);
        while(getline(ifs, fileLine)) {
            toSort.push_back(fileLine);
            //cout << fileLine << endl;
        }
    }
    else{
        while(getline(cin, cinLine)) {
            toSort.push_back(cinLine);
        }
    }

    insertionSort(toSort);

    vector<string>::iterator itr;
    for (itr = toSort.begin(); itr != toSort.end(); itr++) {
        cout << *itr << endl;
    }

    return 0;
}