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

int main(int argc, char const* argv
[]) {
    string inputFile = argv[1];

    //Open the file
    ifstream ifp(inputFile);

    int greatestWords = 0;
    string currentLine = "";
    string longestLine = "";

    while(!ifp.eof()){
        getline(ifp, currentLine);

        int currentWords = numWords(currentLine);

        if(currentWords > greatestWords){
            longestLine = currentLine;
            greatestWords = currentWords;
        }

    }

    cout << longestLine << endl;

    //Close the file
    ifp.close();

    return 0;
}
