```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        char space=' ';
        int i=len-1;
        while(i>=0)
        {
            if(s[i]==space)
                i--;
            else
                break;
        }
        if(i==-1)
            return 0;
        else
        {
            len=i;
        while(i>=0&&s[i]!=space)
            i--;
        }
        return len-i;
    }
};
```
