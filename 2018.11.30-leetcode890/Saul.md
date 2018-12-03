```java
public class Solution {
    public static List<String> findAndReplacePattern(String[] words, String pattern) {
      List<String> result = new ArrayList<>();
      boolean flag = false;
      for (String word : words) {
        if (word.length() != pattern.length()) {
          continue;
        }
        flag = false;
        char[] wordChars = word.toCharArray();
        char[] patternChars = pattern.toCharArray();
        //比较wordChars第i个位置与第j个位置的值，如果相同，那么patternChars第i个位置与第j个位置的值也要相同
        //如果wordChars第i个位置与第j个位置的值不同，那么patternChars第i个位置与第j个位置的值也要不同
        for (int i = 0; i < wordChars.length ; i++) {
          for (int j = i + 1; j < wordChars.length; j++) {
            if (wordChars[i] == wordChars[j]) {
              if (patternChars[i] != patternChars[j]) {
                flag = true;
                break;
              }
            }

            if (wordChars[i] != wordChars[j]) {
              if (patternChars[i] == patternChars[j]) {
                flag = true;
                break;
              }
            }
          }
        }

        if (!flag) {
          result.add(word);
        }
      }
      return result;
    }
  }

```
