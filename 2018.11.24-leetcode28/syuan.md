```
class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.length() == 0)
            return 0;
        char [] charArrayhaystack = haystack.toCharArray();
        char [] charArrayneedle = needle.toCharArray();
        for(int i =0;i<charArrayhaystack.length;i++)
        {
            if(charArrayhaystack[i] == charArrayneedle[0])
            {
                int j = i + 1;
                int k = 1;
                for(k=1;k<charArrayneedle.length && j < charArrayhaystack.length;k++)
                {
                    if(charArrayhaystack[j] == charArrayneedle[k])
                    {
                        j++;
                    }else{
                        break;
                    }
                }
                if(k == charArrayneedle.length)
                    return i;
            }
        }
        return -1;
    }
}
```
