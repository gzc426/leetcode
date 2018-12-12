leetcode of 451
```
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto c : s){
            if(m.count(c) == 0){
                m[c] = 1;
            }else
                ++m[c];
        }
        vector<char> ans;
        for(auto i = m.begin(); i != m.end(); ++i){
            ans.push_back(i->first);
        }
        sort(ans.begin(),ans.end(),[&m](char a,char b){
            return m[a] > m[b];
        });
        string res;
        for(auto c : ans){
            res+=string(m[c],c);
        }
        return res;
        
    }
};
```
