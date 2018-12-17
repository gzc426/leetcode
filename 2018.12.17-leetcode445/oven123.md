```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int sum = 0;int i=0 ;int j=0;
        Arrays.sort(g);
        Arrays.sort(s); //先对两个数组排序
        for(i = 0,j = 0;i<g.length&&j<s.length;)
             if(g[i]<=s[j]){
                 sum++;
                 i++;j++;
             }else{
                 j++;
             }
        

     return sum;
    }
}
```
##思路：
这题不难，由题目可得，开始的时候，只考虑递增数组，那么比较两个数组内元素大小，如果g[i]<=s[i],则满足题目要求，计数，
如果不满足则比较s下一项与g这一项的大小，直至数组结束，很容易即可写出7-16的代码，然而不是递增的情况如何处理，很是费了一番功夫，
后来看以往的题解恍然大悟，可以利用java数组排序的函数，对两个数组排个序，，轻松解决
