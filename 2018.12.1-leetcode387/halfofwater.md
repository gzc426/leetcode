## Leetcode 387

``` C++
class Solution {
public:
    int firstUniqChar(string s) {
       	if (s.size() == 0) return -1;
	if (s.size() < 2) return 0;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	map<char, int> countMap;
	s += '\0';
	char *sHead = (char *)s.data();
	char *head = sHead;
	while (*sHead != '\0')
	{
		countMap[*sHead]++;
		++sHead;
	}
	for (int i = 0; i < s.size(); i++) {
		if (countMap[s[i]] == 1){
			return i;
		}
	}
	return -1;
    }
};
```
