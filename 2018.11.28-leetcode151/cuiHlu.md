    //first reverse the string, second reverse the word
    void reverseWords(string &s) {
        if (s.empty())
            return;
        reverse(s.begin(), s.end());
        int length = s.size();
        int storeIndex = 0;
        for (int i = 0; i < length; ++i)
        {
            if (s[i] != ' ')
            {
                if (storeIndex != 0)
                {
                    s[storeIndex++] = ' ';
                }
                int j = i;
                while (j < length && s[j] != ' ' )
                {
                    s[storeIndex++] = s[j++];
                }
                reverse(s.begin() + storeIndex - j + i, s.begin() + storeIndex);
                i = j;
            }
        }
        s.erase(s.begin() + storeIndex, s.end());
    }
