```
class Solution {
public:
    string frequencySort(string s) {
        int len = s.size();
        unordered_map<char, int> hash;
        vector<string> vec(len+1, "");
        for(auto ch: s) hash[ch]++;
        for(auto val: hash) vec[val.second].append(val.second, val.first);
        string ans;
        for(int i = len; i > 0; i--)
            ans += vec[i];
        return ans;
    }
}; 

```
