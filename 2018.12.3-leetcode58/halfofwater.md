## LeetCode 58

``` C++
class Solution {
public:
    int lengthOfLastWord(string s) {
        
	stringstream input(s);
	string word;
	vector<string> vec;
	while (input >> word) {
		vec.push_back(word);
	}
	if (vec.size() != 0)
		return vec[vec.size() - 1].size();
	else
		return 0;
        
    }
};
```
