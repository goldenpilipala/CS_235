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

    for(int temp = 0; temp <= greaterValue; temp = temp + divisor){
        if(temp > lesserValue)
            output.push_back(temp);
    }

    return output;
}

int main() {

    int start = 0;
    int end = 0;
    int divisor = 0;

    cin >> start >> end >> divisor;

    if(start < end)
        lowToHigh(values(start, end, divisor));
    else
        highToLow(values(start, end, divisor));

    return 0;
}
