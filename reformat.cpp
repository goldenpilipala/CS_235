#include <iostream>
#include <string>
#include <fstream> //reads from a file
#include <sstream> //reads from a string

using namespace std;

int main(int argc, char const* argv[]) {

    string input = argv[1]; //input_file.txt
    string output = argv[2]; //output_file.txt
    //string input = "input_file.txt"; string output = "output_file.txt"; //For testing purposes

    //Open the file
    ifstream ifp; //like cin, but it reads from a file
    ifp.open(input);
    //ifstream ifp(input); //another way to open the file
    ofstream ofp(output);

    string line;
    string firstname, lastname;
    int points;
    double factor;
    while(!ifp.eof()){ //eof = end of file
        getline(ifp, line);
        //cout << "The line is: " << line << endl;

        if(line.length() > 2){ //In case there is extra whitespace
            istringstream iss(line);
            iss >> firstname >> lastname >> points >> factor;
            ofp << lastname << ", " << firstname << ": " << (points*factor) << endl;
        }

    }

    //Close the file
    ifp.close();
    ofp.close();

    return 0;
}