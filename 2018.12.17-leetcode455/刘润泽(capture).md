```java
  public static int findContentChildren(int[] g, int[] s) {
        int count=0;
        int index=0;
        Arrays.sort(g);
        Arrays.sort(s);
        for (int i=0;i<g.length;i++) {

            for (int j=index;j<s.length;j++) {

                if (g[i]<=s[j]){
                    count++;
                    index=j+1;
                    break;
                }
            }
            if(index==s.length) break;
        }
        return count;
    }
```
