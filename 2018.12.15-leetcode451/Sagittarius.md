```
class Solution {
public:
    string frequencySort(string s) {
        vector<string> res(s.size()+1,"");
        map<char,int> hm;
        string st;
        
        for(auto c:s)
            hm[c]++;
        
        for(auto &it:hm)
        {
            int n=it.second;
            char c=it.first;
            res[n].append(n,c);
        }
        
        for(int i=s.size();i>0;i--)
            if(!res[i].empty())
                st.append(res[i]);
        
        return st;
    }
  
};
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
```
