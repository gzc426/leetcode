```
int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int index = upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(index == letters.size()) index = 0;
        return letters[index];
    }
};
```
