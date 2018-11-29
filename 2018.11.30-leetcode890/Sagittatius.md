```
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> s;
        for(int i=0;i<words.size();i++)
        {
            map<char,char> cmap;
            string st="";
            bool flag=true;
            if(words[i].size()!=pattern.size())
                continue;
            for(int j=0,k=0;k<pattern.size();j++,k++)
            {
                if(cmap.find(pattern[k])==cmap.end()&&st.find(words[i][j])==string::npos)
                {
                    cmap[pattern[k]]=words[i][j];
                    st+=words[i][j];
                }
                else if(cmap[pattern[k]]!=words[i][j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)
            {
                s.push_back(words[i]);
            }
        }
        
        return s;
    }
};
```
