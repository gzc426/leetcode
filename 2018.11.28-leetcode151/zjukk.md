```
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

//using stack space O(n)
class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty()) return;
        stack<string> st;
        for (int i = 0; i < s.size(); ++i) {
            string sub;
            while (s[i] != ' ' && i < s.size()) {
                sub.push_back(s[i++]);
            }
            if (!sub.empty()) st.push(sub);//空字符串因为有‘\0’的存在也会被当做一个元素放到stack中
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            res += " ";
            st.pop();
        }
        if (!res.empty()) res.pop_back();
        s = res;
    }
};

class Solution2 {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        is >> s;
        cout << s.size();
        string tmp;
        while (is >> tmp) s = tmp + " " + s;
        // if (!s.empty() && s[0] == ' ') s = "";
    }
};
int main() {
    Solution3 s;
    // string str{"The sky is blue"};
    // string str{"     "};
    string str{"  The sky is blue"};
    // string str{"The sky is blue  "};
    // string str{"The sky    is   blue"};
    s.reverseWords(str);
    cout << str << "*";
}
```
