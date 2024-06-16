#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//Convert to UpperCase
void toUpper(char str[], int n) {
    for(int i=0; i<n; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            continue;
        } else {
            int diff =  str[i] - 'a';
            str[i] = 'A' + diff;
        }
    }
}

//Reverse of a char Array
void reverse(char str[], int n) {
    int st = 0, end = n-1;

    while(st < end) {
        swap(str[st++], str[end--]);
    }
}

//Valid Palindrome
bool isValid(char str[], int n) {
    int st = 0, end = n-1;

    while(st < end) {
        if(str[st++] != str[end--]) {
            cout << "not valid";
            return false;
        }
    }
    cout << "valid";
    return true;
}

//Valid Anagram
bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        int count[26] = {0};
        for(int i=0; i<s.length(); i++) {
            count[s[i]-'a']++;
        }

        for(int i=0; i<t.length(); i++) {
            int idx = t[i] - 'a';
            if(count[idx] == 0) {
                return false;
            }
            count[idx]--;
        }

        return true;
}

int main() {
    //C++ char arrays
    /*char word[20];
    cin.getline(word, 20);
    cout << "your word is : " << word << endl;*/
    
    //<cstring> functions
    /*strcpy(word, "c++");
    cout << "now your word is : " << word << endl;

    strcat(word, " is my favorite");
    cout << word << endl;

    cout << strcmp("hello", "hello") << endl;
    cout << strcmp("abc", "xyz") << endl;*/

    //C++ Strings
    string str;
    getline(cin, str);
    cout << str << endl;

    //String Member Functions
    cout << str.length() << endl;
    cout << str.at(0) << endl;
    cout << str.substr(2, 3) << endl;
    cout << str.find("college") << endl;
    cout << str.find("xyz") << endl;
    return 0;    
}


