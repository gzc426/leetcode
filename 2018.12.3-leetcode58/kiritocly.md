    private static int solution(String input) {
        String[] splits = input.split(" ");
        if (splits.length == 0) {
            return 0;
        }
        return splits[splits.length - 1].length();
    }
