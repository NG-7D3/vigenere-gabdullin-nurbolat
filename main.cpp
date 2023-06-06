#include <iostream>
#include <string>

using namespace std;

string Vigenere(string message, string key) {
    int iter = 0;
    string ans = "";
    for(auto i = message.begin(); i != message.end(); i++) {
        if(*i >= 'a' && *i <= 'z') {
            int x = *i - 'a';
            int y = key[iter] - 'a';
            int z = (x + y) % 26;
            ans.push_back(z + 'a');
            iter++;
        } else if(*i >= 'A' && *i <= 'Z') {
            int x = *i - 'A';
            int y = key[iter] - 'a';
            int z = (x + y) % 26;
            ans.push_back(z + 'A');
            iter++;
        } else {
            ans.push_back(*i);
        }
        if(iter >= key.size())
            iter = 0;
    }
    return ans;
}

string VigenereDecrypt(string message, string key) {
    int iter = 0;
    string ans = "";
    for(auto i = message.begin(); i != message.end(); i++) {
        if(*i >= 'a' && *i <= 'z') {
            int x = *i - 'a';
            int y = key[iter] - 'a';
            int z = ((x - y) + 26) % 26;
            ans.push_back(z + 'a');
            iter++;
        } else if(*i >= 'A' && *i <= 'Z') {
            int x = *i - 'A';
            int y = key[iter] - 'a';
            int z = ((x - y) + 26) % 26;
            ans.push_back(z + 'A');
            iter++;
        } else {
            ans.push_back(*i);
        }
        if(iter >= key.size())
            iter = 0;
    }
    return ans;
}

int main () {
    string key = "apple";
    string message;
    getline(cin, message);
    cout << Vigenere(message, key) << endl;
    cout << VigenereDecrypt(Vigenere(message,key), key);
    return 0;
}
