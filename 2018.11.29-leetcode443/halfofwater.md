## Leetcode 443

```
class Solution {
public:
    int compress(vector<char>& chars) {
        
    if (chars.size() <= 1) return chars.size();

	vector<char>::iterator it = chars.begin();
	++it;
	int count = 1;
	char tmp = chars[0];

	char ccc = *(chars.end() - 1);
	while (it < chars.end())
	{
		if (*it == tmp)
		{

			++count;
			if (it == chars.end() - 1) {
				if (count != 1) {
					
					string s = to_string(count);
					for (char c : s) {
						it = chars.insert(it, c);
						++it;
					}
					it = chars.erase(it);
				}
				//++it;
			}
			else {
				it = chars.erase(it);
			}
		}
		else
		{
			if (count != 1)
			{
				string s = to_string(count);
				for (char c : s)
				{
					it = chars.insert(it, c);
					++it;
				}
			}
			
			tmp = *it;
			count = 1;
			++it;
		}
	}
	return chars.size();
    }
};

```
