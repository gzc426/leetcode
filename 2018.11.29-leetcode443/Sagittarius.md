```
class Solution {
public:
    int compress(vector<char>& chars) {
        int count=0;
        int index=0;
        for(int i=0;i<chars.size();i++)
        {
            count++;
            if(i==chars.size()-1||chars[i]!=chars[i+1])
            {
                chars[index++]=chars[i];
                if(count!=1)
                {
                    for(auto ch:to_string(count))
                    chars[index++]=ch;
                }
                count=0;
            }

        }
        
        return index;
    }
};
```
