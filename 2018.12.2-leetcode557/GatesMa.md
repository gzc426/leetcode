# c++
```cpp
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        string temstr, str;
        ss << s;
        vector<string> strs;
        while(ss){
            ss >> temstr;
            reverse(temstr.begin(),temstr.end());
            strs.push_back(temstr);
        }
        strs.pop_back();
        int len = strs.size();
        str += strs[0];
        for(int i =1;i < len;i++){
            str += " " + strs[i];
        }
        return str;
    }
};
```
