```
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int tmp = 0;
        int size = flowerbed.size();
        if(size == 0 && n!= 0) return false;
        if(size == 0 && n==0)return true;
        if(size == 1 && n>1) return false;
        if(size == 1 && n==1){
            if(flowerbed[0]==0) return true;
            else return false;
        }
        if(flowerbed[1]==0 && flowerbed[0]==0) {
            tmp++;
            flowerbed[0]=1;
        }
        if(flowerbed[size-2]==0 && flowerbed[size-1]==0){
            tmp++;
            flowerbed[size-1]=1;
        } 
        for(int i = 1; i < size -1; i++){
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]==0){
                tmp++; 
                flowerbed[i] = 1;
            }
        }
        if(tmp>=n)return true;
        else return false;
    }
};
```
