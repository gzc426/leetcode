、、、
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isalnum(s[l])) {
              l++; continue;  
            } 
            if (!isalnum(s[r])) {
              r--; continue;  
            } 
            if ((s[l] & 0xDF) != (s[r] & 0xDF)) return false;   //通过位与运算 使小写字母转变为大写     而位或运算（|0x20）可将大写变为小写
            l++; r--;
        }
        return true;
    }
};
、、、
