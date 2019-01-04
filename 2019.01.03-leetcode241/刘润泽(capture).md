```java
  public List<Integer> diffWaysToCompute1(String input) {
        List<Integer> res = new ArrayList<>();
        for (int i=0;i<input.length();i++){
            String tempStr = input.substring(i,i+1);
            if (tempStr.equals("+")||tempStr.equals("-")||tempStr.equals("*")){
                List<Integer> left = diffWaysToCompute1(input.substring(0,i));
                List<Integer> right = diffWaysToCompute1(input.substring(i+1));

                for (int j=0;j<left.size();j++){
                    for (int k=0;k<right.size();k++){
                        if (tempStr.equals("+")){
                            res.add(left.get(j)+right.get(k));
                        }
                        if (tempStr.equals("-")){
                            res.add(left.get(j)-right.get(k));
                        }
                        if (tempStr.equals("*")){
                            res.add(left.get(j)*right.get(k));
                        }
                    }
                }

            }
        }
        if (res.size()==0){
            res.add(Integer.valueOf(input));
        }

        return res;
    }
```
