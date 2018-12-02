## LeetCode 557

``` C++
class Solution {
public:
    string reverseWords(string s) {
        stringstream input(s);
        string word;
        string result;
        while(input>>word){
            reverse(word.begin(), word.end());
            result += word + " ";
        }
        if(!result.empty())
        {
            result.erase(result.find_last_not_of(" ")+1);
        }
        return result;
    }
};
```
