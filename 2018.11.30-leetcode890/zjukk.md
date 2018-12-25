C++:
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (int i = 0; i < words.size(); ++i) {
            map<char,char> mp;
            map<char,char> mp2;
            string word = words[i];
            if (pattern.size() != word.size()) continue;
            int j = 0;
            for (; j < pattern.size(); ++j) {
                if (mp.empty() || mp.count(pattern[j]) == 0) {
                    mp.insert({pattern[j], word[j]});
                } else if (mp[pattern[j]] != word[j]){
                    break;
                }
            }
            if (j != pattern.size()) continue;
            int k = 0;
            for (; k < pattern.size(); ++k) {
                if (mp2.empty() || mp2.count(word[k]) == 0) {
                    mp2.insert({word[k],pattern[k]});
                } else if (mp2[word[k]] != pattern[k]) {
                    break;
                }
            }
            if (k == pattern.size()) res.push_back(word);
        }
        return res;
    }
};
