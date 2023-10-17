#include <iostream>
#include <string>
#include <fstream>

#include "Grid.h"

using namespace std;

//Global variable
ofstream ofs;

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

    //Mark cell as visited
    maze.at(r,c,l) = 2;
    ofs << r << " " << c << " " << l << endl;

    //Last base case
    if((r == maxR) && (c == maxC) && (l == maxL))
        return true; //Reached the end of the maze;

    //Recursion
    if  (solveMaze(maze, r+1, c, l) ||
        solveMaze(maze, r-1, c, l) ||
        solveMaze(maze, r, c+1, l) ||
        solveMaze(maze, r, c-1, l) ||
        solveMaze(maze, r, c, l+1) ||
        solveMaze(maze, r, c, l-1)){
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

    ofs << "SOLUTION" << endl;

    if(!solveMaze(maze, r, c, l)){
        ofs.close();
        ofs.open(outputFile);
        ofs << "NO SOLUTION";
    }

    cout << maze.height() << " " << maze.width() << " " << maze.depth() << endl;

    //Close the file
    ifs.close();
    ofs.close();

    return 0;
}