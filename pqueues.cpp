#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

bool validateOperation(string operation){
    if(operation == "add" || operation == "take" || operation == "")
        return true;
    else{
        cout << "Invalid operation, please try again" << endl;
        return false;
    }
}

bool validateInt(){
    if (cin.fail() || cin.peek() != '\n') {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid priority, please enter an integer" << endl;
        return false;
    }
    else
        return true;
}


void add(priority_queue<string>& Q){
   string name;
   string line;
   int priority;

    //NAME
    cout << "Name: ";
    getline(cin, name);

    //PRIORITY
    cout << "Priority: ";
    getline(cin, line);
    priority = stoi(line);

    if(priority < 10)
        Q.push("0" + to_string(priority) + " - " + name);
    else
        Q.push(to_string(priority) + " - " + name);
}

void take(priority_queue<string>& Q){
    if(Q.size()==0){
        cout << "There are no more people in line" << endl;
        return;
    }
    else{
        cout << Q.top() << endl;
        Q.pop();
    }
}

int main() { //TODO: problems validating data, but it isn't needed for this program
    string operation;
    priority_queue<string> pqNames;

    //OPERATION
    do {
        cout << "What do you want to do? ";
        getline(cin, operation);

    if (operation == "add")
        add(pqNames);
    else if (operation == "take")
        take(pqNames);
    else if (operation == "")
        return 0;

    } while (validateOperation(operation));

    return 0;
}
