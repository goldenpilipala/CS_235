#include <iostream>
#include <string>
#include <fstream>

#include "Grid.h"

using namespace std;

//Global variable
ofstream ofs;
vector<string> solution;

bool solveMaze(Grid maze, int r, int c, int l){
    int maxR = maze.height()-1;
    int maxC = maze.width()-1;
    int maxL = maze. depth()-1;
    //Base cases
    if ((r < 0) || (r > maxR) ||
        (c < 0) || (c > maxC) ||
        (l < 0) || (l > maxL))
        return false; //Out of bounds

    if(maze.at(r,c,l) == 0)
        return false; //Maze wall

    if(maze.at(r,c,l) == 2)
        return false; //I have been here before

    if((r == maxR) && (c == maxC) && (l == maxL)){
        solution.push_back(to_string(r) + " " + to_string(c) + " " + to_string(l));
        return true; //Reached the end of the maze;
    }

    //Mark cell as visited
    maze.at(r,c,l) = 2;

    //Recursion
    if  (solveMaze(maze, r+1, c, l) ||
        solveMaze(maze, r-1, c, l) ||
        solveMaze(maze, r, c+1, l) ||
        solveMaze(maze, r, c-1, l) ||
        solveMaze(maze, r, c, l+1) ||
        solveMaze(maze, r, c, l-1)){
        solution.push_back(to_string(r) + " " + to_string(c) + " " + to_string(l));
        return true;
    }

    return false;
}

int main(int argc, char* argv[]) {
    string inputFile;
    string outputFile;

    if(argc == 3){
        inputFile = argv[1];
        outputFile = argv[2];
    }
    else{
        cerr << "Invalid number of arguments, please try again" << endl;
        return 1;
    }

    ifstream ifs(inputFile);
    Grid maze;
    ifs >> maze;

    int row, column, level;
    row = maze.height();
    column = maze.width();
    level = maze.depth();

    int r=0, c=0, l=0;
    ofs.open(outputFile);

    if(!solveMaze(maze, r, c, l)){
        ofs << "NO SOLUTION";
    }
    else{
        ofs << "SOLUTION" << endl;
        for(auto itr = solution.rbegin(); itr != solution.rend(); itr++){
            string& cell = *itr;
            ofs << cell << endl;
        }
    }

    //cout << maze.height() << " " << maze.width() << " " << maze.depth() << endl;

    //Close the file
    ifs.close();
    ofs.close();

    return 0;
}