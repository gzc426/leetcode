```
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        findIp(s, 0, 0, "", res);
        return res;
    }
    void findIp(string s, int f, int idx, string ip, vector<string> &res){
        if(idx == 3){
            if(s.size() - 1 - f < 3){
                if(s[f] == '0' && f != s.size() - 1) return;
                int num = stoi(s.substr(f, s.size() - f)); 
                if(num < 256){
                    ip += to_string(num);
                    res.push_back(ip);
                }
            }
        }
        else{
            for(int i = 1; i <= 3; i++){
                if(f + i >= s.size()) break;
                int num = stoi(s.substr(f, i));
                if(num < 256)
                    findIp(s, f + i, idx + 1, ip + to_string(num) + ".", res);
                if(s[f] == '0' && i == 1) break;
            }
        }
    }
};
```
