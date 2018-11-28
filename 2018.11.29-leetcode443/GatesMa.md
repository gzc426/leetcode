# c++11
```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> c;
        int num = 1;
        string s;
        char ch = chars[0];
        if(chars.size() == 1){
            return num;
        }
        for(vector<char>::iterator it = chars.begin()+1;it != chars.end(); it++){
            if(ch != *it){
                c.push_back(ch);
                if(num != 1){
                    stringstream ss;
	                ss << num;
                    ss >> s;
                    int len = s.length();
                    for(int i =0;i<len;i++){
                        c.push_back(s[i]);
                    }
                }
                ch = *it;
                num = 1;
            }else{
                num++;
            }
        }
        c.push_back(ch);
        if(num != 1){
            stringstream ss;
            ss << num;
            ss >> s;
            int len = s.length();

            for(int i =0;i<len;i++){
                c.push_back(s[i]);
            }
        }
        chars.clear();
        chars = c;
        return chars.size();
    }
};
```
