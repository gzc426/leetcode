```
class Solution {
    public int compress(char[] chars) {
        char base = chars[0];
        int count = 1;
        int pos = 0;
        for (int i = 1; i < chars.length; i++){
            if (base != chars[i]){
                base = chars[i];
                if (count == 1){
                    chars[++pos] = base;
                    continue;
                }
                // 先计数再写入下一个值
                for (int j = 0; j < String.valueOf(count).length(); j++){
                    chars[++pos] = String.valueOf(count).charAt(j);
                }
                count = 1;
                chars[++pos] = base;
            }
            else {// base == chars[i]
                count ++;
                if (i == chars.length-1){
                    if (count == 1){
                        continue;
                    }
                    for (int j = 0; j < String.valueOf(count).length(); j++){
                        chars[++pos] = String.valueOf(count).charAt(j);
                    }

                }

            }

        }
        pos++;
        //splitArray(chars, pos);
        if (pos == 0)
            return 1;
        return pos;
}
}
```
