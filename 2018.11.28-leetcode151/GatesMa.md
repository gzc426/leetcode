```cpp
class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())
        return ;
      stringstream ss(s);
      vector<string> words;
      string word;
      while(ss>>word)
      words.push_back(word+' ');
      if(!words.empty())
      {
          s.clear();
          
          for(int i=words.size()-1;i>=0;i--)
          {
              s+= words[i];            
          }
          //s = s.substr(0,s.length()-1);
          s.pop_back();
      }
      else
      {
          s.clear();
      }
    }
};
```
