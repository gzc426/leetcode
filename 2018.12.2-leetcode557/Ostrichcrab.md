```
class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        int len = s.length();
        int left = 0, right = 0;
        for(int i = 0; i < len; i++){
            while(s[i]!=' ') right++,i++;
            reverse(s.begin()+left,s.begin()+right);
            right++;
            left=right;
        }
        s.pop_back();
        cout<<s<<endl;
        return s;
    }
};
```
