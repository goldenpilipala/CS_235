#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int numWords(string line){
    istringstream iss(line);
    string oneWord;

    int i=0;
    while(iss >> oneWord)
        i++;

    return i;
}

int main(int argc, char const* argv[]) {
    string inputFile = argv[1];
    //string inputFile = "example.txt"; //For testing purposes

    //cout << "Test 1" << endl;

    //Open the file
    ifstream ifp(inputFile);

    int wordsLastLine = 0;
    string currentLine = "";
    string longestLine = "";

    while(!ifp.eof()){
        getline(ifp, currentLine);

        //cout << "Test 2: " << currentLine << endl;

        if(numWords(currentLine) > wordsLastLine)
            longestLine = currentLine;

        wordsLastLine = numWords(currentLine);
    }

    cout << longestLine << endl;

    //Close the file
    ifp.close();

    return 0;
}
