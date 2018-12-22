```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for(int i = 0; i < flowerbed.length; i++){
            if(n == 0){
                return true;
            }
            if(flowerbed[i] == 0){
                if(i - 1 < 0){
                    if(i + 1 < flowerbed.length&&flowerbed[i + 1] == 0){
                        flowerbed[i] = 1;
                        n--;
                    }
                    if(i + 1 >= flowerbed.length){
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else if(i + 1 == flowerbed.length){
                    if(i - 1 >= 0&&flowerbed[i - 1] == 0){
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else{
                    if(flowerbed[i - 1] == 0&&flowerbed[i + 1] == 0){
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            }
        }
        return n == 0;
    }
}
```
