```
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        bool flag = false;
        while (l <= r) {
            if (!isAlphaNum(s[l])) {
                ++l; continue;
            }
            if (!isAlphaNum(s[r])) {
                --r; continue;
            }
            if ((s[r] + 32 - 'a') % 32 != (s[l] + 32 - 'a') % 32) {flag = true; break;}
            ++l; --r;
    }
        return !flag;
    }
    bool isAlphaNum(char c) {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("race a car");
    //A man, a plan, a canal: Panama
}
```
