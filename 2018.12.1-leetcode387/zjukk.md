#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> m;
        for (char c : s) {
            if (!m.count(c)) {
                m[c] = 1;
            } else {
                ++m[c];
            }
        }
        int i = 0;
        for (; i < s.size(); ++i) {
            if (m[s[i]] == 1) return i;
        }
        if (i == s.size()) return -1;
    }
};
class Solution2 {
public:
    int firstUniqChar(string s) {
        int list[256] = {0};
        for (auto c : s) {
            ++list[c];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (list[s[i]] == 1) return i;
        }
        return -1;
    }
};
