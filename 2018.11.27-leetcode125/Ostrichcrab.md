```
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0) return true;
        string t = "";
        for(int i = 0; i < s.length(); i++){
            
                if(s[i]>='a'&&s[i]<='z'){
                    t += s[i];
                }else if(s[i]>='A'&&s[i]<='Z'){
                    t += 'a' + s[i] - 'A';
                }else if(s[i]>='0'&&s[i]<='9'){
                    t += s[i];
                }
        }
        string tt = t;
        reverse(tt.begin(),tt.end());
        for(int i = 0; i < t.length(); i++){
            if(t[i]!=tt[i]) return false;
        }
        return true;
    }
};
```
