```java
    public List<List<Integer>> combine(int n, int k) {

        List<List<Integer>> res = new ArrayList<>();
        int[] box = new int[k];
        fenzhi(0,0,n,k,box,res);

        return res;
    }

    public void fenzhi(int deep, int index, int n, int k, int[] box, List<List<Integer>> res){

        if (deep==k){
            List<Integer> tempList = new ArrayList<>();
            for (int i=0;i<box.length;i++){
                tempList.add(box[i]);
            }
            res.add(tempList);
            return;
        }

        for (int i=index+1;i<=n;i++){

            box[deep]=i;
            fenzhi(deep+1,i,n,k,box,res);
        }
    }
```
