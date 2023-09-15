#include <iostream>
#include <vector>

using namespace std;

void lowToHigh(vector<int> output){
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
}

void highToLow(vector<int> output){
    for(int i = output.size()-1; i >= 0; i--)
        cout << output[i] << endl;
}

vector<int> negNums(int lesser, int greater, int divisor){
    vector<int> numsDecreasing;
    for(int i = 0; i >= lesser; i=i-divisor){
        if(i < greater && i != 0)
            numsDecreasing.push_back(i);
    }
    return numsDecreasing;
}

vector<int> values(int start, int end, int divisor){
    vector<int> output;
    int greaterValue;
    int lesserValue;

    if(start>end){
        greaterValue = start;
        lesserValue = end;
    }
    else{
        greaterValue = end;
        lesserValue = start;
    }

    if(lesserValue < 0){ //Account for negative numbers
        vector<int> numsDecreasing = negNums(lesserValue, greaterValue, divisor);
        for(int i = numsDecreasing.size()-1; i >= 0; i--){
            output.push_back(numsDecreasing[i]); //Adds numsDecreasing to output in increasing order
        }
    }

    for(int k = 0; k <= greaterValue; k = k+divisor){
        if(k > lesserValue)
            output.push_back(k);
    }

    return output;
}

int main(int argc, char const* argv[]) {

    //int start, end, divisor; cin >> start >> end >> divisor; //For testing purposes

    int start = stoi(argv[1]);
    int end = stoi(argv[2]);
    int divisor = stoi(argv[3]);

    if(start < end)
        lowToHigh(values(start, end, divisor));
    else
        highToLow(values(start, end, divisor));

    return 0;
}
