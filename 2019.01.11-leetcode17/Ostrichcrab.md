```
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits.size()==0)return res;
        string list[]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        res.push_back("");
        for(int i=0;i<digits.size();++i){
            int len=res.size();
            string str=list[digits[i]-'1'];
            for(int j=0;j<len;++j){
                string tmp=res.front();
                res.erase(res.begin());
                for(int k=0;k<str.size();++k)
                    res.push_back(tmp+str[k]);         
            }        
        }
       return res;        
    }
    
};

```
