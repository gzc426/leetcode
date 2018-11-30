## Leetcode 151

```
class Solution {
public:
    void reverseWords(string &s) {
        
        
        vector<string> res;
        int head=0, tail=0;

        # 去掉首尾空格
        if(!s.empty()){
            s.erase(0,s.find_first_not_of(" "));
            s.erase(s.find_last_not_of(" ") + 1);
        }
        int len = s.size();
        int flag = 0;
        int j=0;
        for(int i=0;i<len;i++)
        {
            if(flag == 0){
                if(s[i] == ' ' || i == len-1){
                   if (i == len - 1)
				{
					res.push_back(s.substr(j, i - j+1));
				}
				else {
					res.push_back(s.substr(j, i - j));
				}
				flag = 1;
                }
            }else if(flag == 1){
                if(s[i] != ' '){
                    flag = 0;
                    j = i;
                    if (i == len - 1) 
                    {
					res.push_back(s.substr(i, i-j+1));
				    }
                }
            }
        }
        s.erase(0);
        for(int i=res.size()-1;i>=0;i--)
        {
                s += res[i];
                s += ' ';
        }
        s.erase(s.find_last_not_of(' ')+1);
    }
};

```

## Performance:

Beyond the 99.86% of commits.
