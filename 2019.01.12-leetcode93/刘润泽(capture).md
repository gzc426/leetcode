```java
    public List<String> restoreIpAddresses(String s) {

        List<String> res = new ArrayList<>();
        if (s.length()<4||s.length()>12) return res;
        getRes(s,4,"",res);
        return res;
    }

    public void getRes(String currStr, int rdeep, String currResStr, List<String> res){
        if (currStr.length()<rdeep*1||currStr.length()>rdeep*3) return;
        if (rdeep==1){
            if (currStr.length()>1&&currStr.startsWith("0")) return;//排除长度大于1且开头为0的情况
            if (currStr.length()==3&&Integer.valueOf(currStr)>255) return;//排除长度为3且大于255的情况
            res.add(currResStr+"."+currStr);
            return;
        }
        for (int i=1;i<4;i++){
            if (i>=currStr.length()) break;
            if (i>1&&currStr.startsWith("0")) break; //排除长度大于1且开头为0的情况
            if (i!=3||Integer.valueOf(currStr.substring(0,i))<=255) {  //排除长度为3且大于255的情况
                if (currResStr.equals("")) {
                    getRes(currStr.substring(i),rdeep-1,currStr.substring(0,i),res);
                }else{
                    getRes(currStr.substring(i),rdeep-1,currResStr+"."+currStr.substring(0,i),res);
                }

            }
        }
    }
```
