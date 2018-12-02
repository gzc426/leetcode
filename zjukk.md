```
class Solution {
public:
    string reverseWords(string s) {
        
        istringstream is(s);
        string res;
        string tmp;
        is >> tmp;//第一个字符串单独处理
        res += reverse(tmp);
        // cout << reverse(tmp);
        while (is >> tmp) {
            // cout << " " << reverse(tmp);
            res += " ";
            res += reverse(tmp);
        }
        return res;
    }
    string reverse(string& s) {
        string res = s;
        int n = s.size() - 1;
        for (int i = 0; i < s.size(); ++i) {
            res[i] = s[n-i];
        }
        return res;
    }
};
```
