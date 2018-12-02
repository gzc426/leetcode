```
class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        if(len == 1) return chars.size();
        chars.push_back(' ');//统一一下
        len++;
        int cnt = 1;
        char pre = ' ';
        pre = chars[0];
        for(int i = 1; i < len; i++){
            if(chars[i] == pre){
                chars.erase(chars.begin()+i);
                i--;
                len--;
                cnt++;
            }    else if(cnt>1){
                stringstream ss;
                string s;
                ss<<cnt;
                ss>>s;
                pre=chars[i];
                for(int j = 0; j < s.size(); j++){
                    chars.insert(chars.begin()+i,s[j]);
                    i++;
                    len++;
                }
                cnt=1;
            }
            pre = chars[i];
        }
        chars.pop_back();//最后去除
        return chars.size();
    }
};
```
