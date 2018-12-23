# LeetCode 406
    public static  int[][] reconstructQueue(int[][] people) {//先按照身高降序排列，身高相同的按照位置升序排列，然后对排序后的数据进行依次插入到数组中；
        if (people == null || people.length == 0 || people[0].length == 0) {
            return new int[0][0];
        }
        Arrays.sort(people, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) {
                    return o1[1] - o2[1];
                }
                return o2[0] - o1[0];
            }
        });
        List<int[]> list = new ArrayList<>();
        for (int i = 0; i < people.length; i++) {
            list.add(people[i][1], new int[]{people[i][0], people[i][1]});
        }
        for (int i = 0; i < list.size(); i++) {
            people[i][0] =  list.get(i)[0];
            people[i][1] =  list.get(i)[1];
        }
        return people;
    }
