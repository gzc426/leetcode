//leetcode off 58
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==0) return 0;
        int i=s.size()-1;
        while(i>=0 && s[i]==' '){
            i--;
        }
        int count=0;
        while(i>=0 && (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            i--;
            count++;
        }
        return count;
        
    }
};
