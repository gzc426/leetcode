```
class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream is(s);
        string tmp;
        while (is >> tmp);
        return tmp.size();
    }
};
```
