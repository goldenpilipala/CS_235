#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double add(double leftOperand, double rightOperand);
double subtract(double leftOperand, double rightOperand);
double multiply(double leftOperand, double rightOperand);
double divide(double leftOperand, double rightOperand);
double mod(double leftOperand, double rightOperand);

string input(string prompt) {
    cout << prompt;
    cout.flush();
    string response;
    getline(cin, response);
    return response;
}

int main(int argc, char const* argv[]) {
    cout << endl;
    /*cout << "Welcome to the calculator!\n"
            "Please choose one of the following operations:" << endl;
    cout << "1) add\n"
            "2) subtract\n"
            "3) multiply\n"
            "4) divide\n"
            "5) mod" << endl;*/

    string operation = "null";
    double leftOperand = 0;
    double rightOperand = 0;

    while(true) {

        bool notValidOperation = true;

        while (notValidOperation) {

            //----------GETTING THE OPERATION-----------//

            //cout << endl << "Operation: ";
            //cin >> operation;

            operation = input("\noperation: ");

            //----------VALIDATING THE OPERATION-----------//

            if (operation == "add" || operation == "subtract" || operation == "multiply" ||
                operation == "divide" || operation == "mod" || operation == "") {
                notValidOperation = false;
            } else {
                cout << operation << " isn't a valid operation.";
                notValidOperation = true;
            }
        }

        //----------BREAKING LOOP ON EMPTY LINE-----------//
            //only for the while(true) loop, I was testing out a different loop too

        if(operation == "") //FIX: It always breaks after the first iteration of the loop!
            break;

        //----------GETTING THE OPERANDS-----------//

        /*cout << "Left Operand: ";
        cin >> leftOperand;
        cout << "Right Operand: ";
        cin >> rightOperand;
        cin.ignore(); //The KEY*/

        leftOperand = stod(input("left operand: ")); //stod()- convert from string to double
        rightOperand = stod(input("right operand: "));
            //Btw, this does not valid the input, but it does throw an error
            /*Throws an error before even asking for input:
             * terminate called after throwing an instance of 'std::invalid_argument'
             * what():  stod
             *
             * UPDATE: after adding cin.ignore() in the input() function, it now throws and error AFTER getting
             * the inputs
             * */


        //----------CALLING THE FUNCTIONS-----------//

        if(operation == "add")
            cout << add(leftOperand, rightOperand);
        if(operation == "subtract")
            cout << subtract(leftOperand, rightOperand);
        if(operation == "multiply")
            cout << multiply(leftOperand, rightOperand);
        if(operation == "divide")
            cout << divide(leftOperand, rightOperand);
        if(operation == "mod")
            cout << mod(leftOperand, rightOperand);
    }

    cout << "\nCongrats! You made it to the end of the program";

    return 0;
}

double add(double leftOperand, double rightOperand){
    //cout << "You accessed the add function: ";
    return leftOperand + rightOperand;
}

double subtract(double leftOperand, double rightOperand){
    //cout << "You accessed the subtract function: ";
    return leftOperand - rightOperand;
}

double multiply(double leftOperand, double rightOperand){
    //cout << "You accessed the multiply function: ";
    return leftOperand * rightOperand;
}

double divide(double leftOperand, double rightOperand){
    //cout << "You accessed the divide function: ";
    return leftOperand / rightOperand;
}

double mod(double leftOperand, double rightOperand){
    //cout << "You accessed the mod function: ";
    // The % operator only works for ints
    return fmod(leftOperand, rightOperand);
}
