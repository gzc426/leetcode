```
class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())
            s="";
        stack<string> str;
        string s1;
        int i=0;
        while(i<s.size())
        {
            int flag=0;
            while(s[i]==' ')
                i++;
            while(s[i]!=' '&&i<s.size())
            {
                flag=1;
                s1+=s[i];
                i++;
            }
            if(1==flag)
            {
                str.push(s1);
                s1="";
            }
        }
        s="";
        while(!str.empty())
        {
            s=s+str.top();
            str.pop();
            if(!str.empty())
                s=s+" ";
        }
    }
};
```
