```
class Solution {
public:
    string reverseWords(string s) {
        string rs="";
        stack<char> a;
        int i=0;
        while(i<s.size())
        {
            while(i<s.size()&&s[i]!=' ')
            {
                a.push(s[i]);
                i++;
            }
            while(!a.empty())
            {
                rs+=a.top();
                a.pop();
            }
            i++;
            if(i<s.size())
                rs+=' ';
        }
        
        return rs;
    }
};
```
