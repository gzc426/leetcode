```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {

        int distance = Integer.MAX_VALUE;
        int index = -1;
        for(int i = 0; i < letters.length; i++){
            int tempDis = (int)(letters[i] - target);
            if(tempDis < 0){
                tempDis += 26;
            }
            if(tempDis > 0&&tempDis < distance){
                distance = tempDis;
                index = i;
            }
        }
        return letters[index];
    }
}
```
