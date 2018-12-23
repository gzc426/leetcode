```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ls = s.length();
        int lt = t.length();
        int i =0; int j = 0;
        for(; i!=ls&&j!=lt;){
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i==ls) return true;
        else return false;
    }
};
```
