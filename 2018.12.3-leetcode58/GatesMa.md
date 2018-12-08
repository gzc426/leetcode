# c++
```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss;
        ss << s;
        string str;
        while(ss){
            ss >> str;
        }
        return str.length();
    }
};
```
