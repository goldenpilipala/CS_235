#include <iostream>
#include <string>
#include <cstring> //For strlen function
#include <fstream>

using namespace std;

int main(int argc, char const* argv[]) {

    //Finding numLines and textFile
    int numLines = 10;
    string textFile = "notAFile.haha";

    for(int i=1; i<argc; i++){
        string line = argv[i];
        int wordSize = strlen(argv[i]);

        if(argv[i][0] == '-') //Signifies how many lines
            numLines = stoi(line.substr(1));

        if(wordSize >= 4){
            if(line.substr(wordSize-4) == ".txt")
                textFile = line;
        }
    }

    //If no file is provided, read from cin
    if(textFile == "notAFile.haha"){
        string line;
        int k=0;
        while(getline(cin, line)){
            if(k < numLines)
                cout << line << endl;
            k++;
        }
        return 0;
    }

    //Opening file
    ifstream ifs(textFile);

    //Check to see if file exists
    if(!ifs.good()){
        cerr << "File does not exist" << endl;
        return 1;
    }

    //See if lines in the file are less than numLines, and if so reassign numLines
    int i = 0;
    while(!ifs.eof()){
        string line;
        getline(ifs, line);
        i++;
    }
    if(i < numLines)
        numLines = i;

    //Print numLines of file
    ifs.close();
    ifs.open(textFile); //resets getline()
    string toPrint;

    for(int j=0; j<numLines; j++){
        getline(ifs, toPrint);
        cout << toPrint << endl;
    }

    //cout << "Lines: " << numLines << endl << "File: " << textFile << endl;

    //Close the file
    ifs.close();

    return 0;
}