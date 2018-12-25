leetcode of 557
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string t;
        stringstream ss(s);
        int start = 1;
        while(getline(ss,t,' ')){
            reverse(t.begin(),t.end());
            if(start){
                ans = t;
                start = 0;
            }else{
                ans += " "+t;
            }
        }
        return ans;
        
    }
};
