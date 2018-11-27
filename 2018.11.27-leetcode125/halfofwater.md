## leetcode 125

```
class Solution {
public:
    bool isPalindrome(string s) {
        string::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		//bool b1 = !(65 <= *it && *it <= 90);
		//bool b2 = !(97 <= *it && *it <= 122);
		//bool b3 = !(48 <= *it && *it <= 57);

		if (!(65 <= *it && *it<= 90) && !(97 <= *it && *it <= 122) && !(48 <= *it && *it <= 57))
		{
			s.erase(it);
			it--;
		}
		if (65 <= *it && *it <= 90)
		{
			*it += 32;
		}
	}
	int len = s.size();
	int i = 0, j = len - 1;
	while (i < j)
	{
		if (s[i] != s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
    }
};
```
