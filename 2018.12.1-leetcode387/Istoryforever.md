//leetcode of 387
class Solution {
public:
    int firstUniqChar(string s) {
        
    //}
    //int firstUniqChar(char* s) {
    unordered_map<char,int> m;
    //string ss(s);
    for(auto c : s){
        if(m.count(c) == 0) m[c]=1;
        else m[c]++;
    }
    for(auto i = s.begin();i!=s.end();i++){
        if(m[*i] == 1) return i-s.begin();
    }
    return -1;
    
}
};
