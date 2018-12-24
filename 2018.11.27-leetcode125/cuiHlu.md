  //isalnum()判断是否为字母或者是数字
  bool isPalindrome(string s) {
        int length = s.size();
        int start = 0;
        int end = start + length - 1;
        while (start <= end)
        {
            if (!isalnum(s[start]))
                ++start;
            else if (!isalnum(s[end]))
                --end;
            else
            {
                if (tolower(s[start]) != tolower(s[end]))
                    return false;
                ++start;
                --end;
            }
        }
        return true;
    }
