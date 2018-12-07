```
class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s[s.length()-1]==' ') s.pop_back();
        s.insert(s.begin(),' ');
        reverse(s.begin(),s.end());
        int len = 0;
        for(int i = 0; i < s.length(); i++)
        {
            while(s[i]!=' ')
            {
                len++;
                i++;
            }
            break;
        }
        return len;
    }
};
```
