# c++
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int chnum[26];
        memset(chnum, 0, sizeof(chnum));
        int len = s.length();
        for(int i=0;i<len;i++){
            chnum[s[i] - 'a']++;
        }
        for(int i=0;i < len;i++){
            if(chnum[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};
```
