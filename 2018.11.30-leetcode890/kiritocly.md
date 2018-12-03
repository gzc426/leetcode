    private static List<String> solution(String[] words, String pattern) {
        //定义一个list存放结果字符串
        List<String> result = new ArrayList<>();
        char[] patternArray = pattern.toCharArray();
        //遍历字符串
        for (int i = 0; i < words.length; i++) {
            //匹配字符串
            char[] wordArray = words[i].toCharArray();
            //是否匹配
            boolean flag = true;
            //长度相同才能匹配
            if (wordArray.length == patternArray.length) {
                //定义两个hashMap存放映射:words中的单词与pattern
                Map<Character, Character> hashMap1 = new HashMap<>();
                Map<Character, Character> hashMap2 = new HashMap<>();
                //逐个字符匹配
                for (int j = 0; j < patternArray.length; j++) {
                    if (!hashMap1.containsKey(patternArray[j])) {
                        //如果不存在字符则向hashMap1存放映射关系对
                        hashMap1.put(patternArray[j], wordArray[j]);
                        //判断hashMap2中是否存在反向映射关系对
                        if (!hashMap2.containsKey(wordArray[j])) {
                            hashMap2.put(wordArray[j], patternArray[j]);
                        } else {
                            if (hashMap2.get(wordArray[j]) != patternArray[j]) {
                                //存在反向字符且当前判断的字符不相同
                                flag = false;
                                break;
                            }

                        }
                    } else {
                        if (hashMap1.get(patternArray[j]) != wordArray[j]) {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if (flag) {
                result.add(words[i]);
            }
        }
        return result;
    }
