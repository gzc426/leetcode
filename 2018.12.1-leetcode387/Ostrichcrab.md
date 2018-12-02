```
class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        if(len==1) return 0;
        map <char,int> mp;
        int ans = -1;
        for(int i = len-1; i >= 0; i--){
            mp[s[i]]++;
        }
        for(int i = len-1; i>= 0; i--){
            if(mp[s[i]]==1) ans = i;
        }
        return ans;
       
    }
};
```
