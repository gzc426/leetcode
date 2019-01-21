```java
    public List<List<Integer>> combinationSum3(int k, int n) {

        List<List<Integer>> res = new ArrayList<>();
        List<Integer> box = new ArrayList<>();
        search(k,0,n,box,res);
        return res;
    }

    public void search(int k, int lastCount, int n, List<Integer> box, List<List<Integer>> res){


        if (k<0||n<0) return;

        if (n==0&&k==0){
            res.add(new ArrayList<Integer>(box));
        }

        for (int i=lastCount+1;i<=n&&i<10;i++){
            box.add(i);
            search(k-1,i,n-i,box,res);
            box.remove(box.size()-1);
        }

    }
```
