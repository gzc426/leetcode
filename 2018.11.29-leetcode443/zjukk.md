```
class Solution {
public:
    int compress(vector<char>& chars) {
        int N = chars.size();
        int idx = 0, cnt = 0;
        
        for(int i = 0; i < N; ++i) {
            cnt++;
            if (i == N-1 || chars[i] != chars[i+1]) {
                chars[idx++] = chars[i];
                if (cnt > 1) {
                    for(auto c : to_string(cnt))
                        chars[idx++] = c;
                 } 
                cnt = 0;
            }
        }
        return idx;
    }
};
```
