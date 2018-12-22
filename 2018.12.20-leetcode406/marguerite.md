给出了一些人的身高和这个人前面身高大于等于他的人数，对这些人进行排队，使得所有人的情况都得到满足。这道题的思路是(贪心算法)：

　　(1)首先找到身高最高的人并对他们进行排序。

　　(2)然后找到身高次高的人，按照他们的前面的人数把他们插入到最高的人群中。

因此这是一个排序和插入的过程，按照身高进行降序排序，然后把身高相同的人按照k进行升序排序。每次取出身高相同的一组人，按照k值把他们插入到队列中。

```
public class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, new Comparator<int []>() {        //按身高降序排序(h大的在前面)，按k的大小升序排列(k小的在前面)
            public int compare(int[] a, int[] b) {
                if(a[0] != b[0]) return -a[0]+b[0];
                else return a[1]-b[1];
            }
        });
         
        List<int[]>  res=new LinkedList<>();        //保存结果
         
        for(int i=0;i<people.length;i++){
            int[] peo = people[i];
            res.add(peo[1], peo);
        }
         
        return res.toArray(new int[people.length][]);
    }
```
