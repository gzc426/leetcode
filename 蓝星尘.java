class Solution {
    public static int[][] reconstructQueue(int[][] people) {
        if(people == null) {
            return null;
        }
        Arrays.sort(people, new Comparator<int[]>() {
            @Override
            public int compare(int[] n1, int[] n2) {//第一数按降序，第二个数按升序
                if(n1[0] > n2[0]) {
                    return -1;
                }
                if(n1[0] < n2[0]) {
                    return 1;
                } else {
                    if(n1[1] < n2[1]) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        });
        for(int i = 1; i < people.length; i++) {
            int[] current = people[i];
            int j;
            int index = people[i][1];
            for(j = i; j > index; j--) {
                people[j] = people[j - 1];
            }
            people[j] = current;
        }
        
        return people;
    }
}