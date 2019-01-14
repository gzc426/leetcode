```java
  public List<String> letterCombinations(String digits) {
        List<String> res =  new ArrayList<String>();
        if (digits.length()==0) return res;
        Map<String,String[]> map = new HashMap<>();
        map.put("2",new String[]{"a","b","c"});
        map.put("3",new String[]{"d","e","f"});
        map.put("4",new String[]{"g","h","i"});
        map.put("5",new String[]{"j","k","l"});
        map.put("6",new String[]{"m","n","o"});
        map.put("7",new String[]{"p","q","r","s"});
        map.put("8",new String[]{"t","u","v"});
        map.put("9",new String[]{"w","x","y","z"});

        List<String[]> list = new ArrayList<>();
        for (int i=0;i<digits.length();i++){
            list.add(map.get(digits.substring(i,i+1)));
        }

        depthSearch(list,0,list.get(0).length,res,"");

        return res;

    }

    public void depthSearch(List<String[]> list, int depth, int width, List<String> res, String tempStr){
        for (int i=0;i<width;i++){

            String currStr = tempStr+list.get(depth)[i];
            if (depth+1==list.size()) {
                res.add(currStr.toString());
            }

            if (depth+1<list.size()) depthSearch(list,depth+1, list.get(depth+1).length, res, currStr);
        }
    }
```
