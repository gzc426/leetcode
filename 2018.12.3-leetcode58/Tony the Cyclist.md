Java
```
class Solution {
    public int lengthOfLastWord(String s) {
        String [] ss = s.trim().split(" ");
        return ss[ss.length-1].length();
    }
}
```

Python
```
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = s.strip().split(' ')
        return len(l[-1])
```
C++
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = (int)s.length();
        int left = 0;
        int right = len - 1;
        int count = 0;
        while (s[left] == ' '){
            left ++;
        }
        while (s[right] == ' ') {
            right --;
        }
        //string ss = s.substr(left, right+1);
        for (int i = left; i < right+1; i++){
            if (s[i] == ' '){
                count = 0;
            }
            else{
                count ++;
            }
        }
        return count;
    }
};
```
