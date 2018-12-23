```
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int size = S.length();
        map<char, int > d;
        for(int i = 0; i < size; i++) d[S[i]] = i;
        int start = 0; int end = 0;
        vector<int> res;
        for(int i = 0; i < size; i++){
            end = end>d[S[i]]?end:d[S[i]];
            if(i == end ){
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
```
