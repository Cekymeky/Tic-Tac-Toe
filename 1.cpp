#include <bits/stdc++.h>
#include <cctype>
#include <fstream>
using namespace std;

string remove_non_alpha(const string& n) {
    string s;
    for (char a : n) {
        if (isalnum(a) || a == '-' || a ==' '){
            s += a;
        }
    }
    return s;
}

int main() {
    string f;
    cout << "Please enter the file name: ";
    cin >> f;

    string line;
    ifstream ifel(f);
    map<string, int> en;  

    while (getline(ifel, line)) {
        line = remove_non_alpha(line);

        istringstream ivel(line);
        string word;

        while (ivel >> word) {
            en[word] += 1;
        }
    }

    for ( auto i  : en) {
        cout << i.first << ": " << i.second << endl;
    }

    return 0;
}














