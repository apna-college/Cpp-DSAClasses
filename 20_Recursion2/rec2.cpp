#include <iostream>
#include <string>
using namespace std;

//Tiling Problem
int countWays(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }

    //vertical choice
    int ways1 = countWays(n-1);

    //horizonal choice
    int ways2 = countWays(n-2);

    return ways1 + ways2;
}

//Remove Duplicates
void removeDuplicates(string str, int i, bool map[26], string ans) {
    if(i == str.length()) {
        cout << "ans : " << ans << endl;
        return;
    }

    int mapIdx = (int)(str.at(i) - 'a');

    if(map[mapIdx]) {
        removeDuplicates(str, i+1, map, ans);
    } else {
        map[mapIdx] = true;
        removeDuplicates(str, i+1, map, ans+str.at(i));
    }
    
}

//Friends Pairing Problem
int pairFriends(int n) {
    if(n == 1 || n == 2) {
        return n;
    }

    return pairFriends(n-1) + (n-1) * pairFriends(n-2);
}

//Binary Strings Problem
void binStrings(int n, string ans, int lastPlace) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    binStrings(n-1, ans+'0', 0);

    if(lastPlace != 0) {
        binStrings(n-1, ans+'1', 1);
    }
}

void binStrings(int n, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    binStrings(n-1, ans+'0');

    if(ans[ans.size()-1] != '1') {
        binStrings(n-1, ans+'1');
    }
}

int main() {
    cout << countWays(4) << endl;

    string ans = "";
    bool map[26] = {false};
    removeDuplicates("appnnacollege", 0, map, ans); //apncoleg

    cout << pairFriends(3) << endl;

    ans = "";
    //binStrings(3, ans, 0);

    binStrings(3, ans);
    return 0;    
}


