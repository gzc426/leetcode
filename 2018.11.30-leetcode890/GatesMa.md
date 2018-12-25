# C++
```
class Solution {
public:
    bool strMatch(string str, string pattern){
        int len = str.length();
        for(int i=0;i < len;i++){
            for(int j=i+1;j < len;j++){
                if((str[i] == str[j]) && (pattern[i] != pattern[j])) return false;
                if((str[i] != str[j]) && (pattern[i] == pattern[j])) return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> set;
        for(int i=0;i < words.size();i++){
            if(strMatch(words[i], pattern)){
                set.push_back(words[i]);
            }
        }
        return set;
    }
};
```
