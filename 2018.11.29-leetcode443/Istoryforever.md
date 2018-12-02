//Leetcode of 443
class Solution {
public:
    int compress(vector<char>& chars) {
        stringstream s;
        int count = 1;
       // chars.push_back(0);
        for(int i = 0;i < chars.size();i++){
            
            if(i == 0){
                 s<<chars[i];
            }
            else if(i != 0  && chars[i] == chars[i-1]){
                ++count;
                if(i == chars.size()-1){
                     s<<count;
                }
                    
            }else if(i!=0){
                if(count != 1)
                     s<<count;
                s<<chars[i];
                count = 1;
            }
        }
        string ans = s.str();
        chars.assign(ans.begin(),ans.end());
        return ans.size();
    
        
    }
};
