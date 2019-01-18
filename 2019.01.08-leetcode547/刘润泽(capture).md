```java
  public int findCircleNum(int[][] M) {

        int circleNum=0;
        int[] temp = new int[M.length];
        for (int i : temp){
            temp[i]=0;
        }
        for (int i=0;i<temp.length;i++){
            if (temp[i]==1) continue;
            if (temp[i]==0){
                findFriend(i,M,temp);
                circleNum++;
            }
        }

        return circleNum;
    }

    public void findFriend(int n, int[][]M, int[] temp){
        temp[n]=1;
        for (int i=0;i<M.length;i++){
            if (temp[i]==1) continue;
            if(M[n][i]==1){
                findFriend(i,M,temp);
            }
        }
    }
```
