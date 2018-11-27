leetcode of 151
```
class Solution {
public:
    void reverseWords(string &s) {
        vector<string> ans;
        string t="";
        for(auto c = s.begin(); c!=s.end(); c++){
            if(*c ==' '){
                if(t != ""){
                    ans.push_back(t);
                    t="";
                }
                continue;
            }
            t+=*c;
            if(c == s.end()-1){
                ans.push_back(t);
            }
        }
        reverse(ans.begin(),ans.end());
        s="";
        for (auto i = ans.begin();i != ans.end(); i++){
            if(i == ans.begin()) s=*i;
            else{
                s+=" "+*i;
            }
        }
    }
};
```
