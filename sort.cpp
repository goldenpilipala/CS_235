#include <iostream>
#include <string>

using namespace std;

void switchWords(string& x, string& y){
    string temp = y;
    y = x;
    x = temp;
}

void sort(string& a, string& b, string& c) {

    if(a > b)
        switchWords(a, b);
    if(b > c)
        switchWords(b, c);
    if(a > b)
        switchWords(a, b);

}



int main(int argc, char const* argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " a b c" << endl;
        return 1;
    }

    string a = argv[1];
    string b = argv[2];
    string c = argv[3];

    sort(a, b, c);

    cout << a << ' ' << b << ' ' << c << endl;

    cout << "what " << a[14] << " is this" << endl;

    return 0;
}