public static int compress(char[] chars) {
		Map<Character, String> map = new LinkedHashMap();
		int len = chars.length;
		for (int i = 0; i<len;i++){
			if (map.containsKey(chars[i])){
				map.put(chars[i],String.valueOf(Integer.parseInt(map.get(chars[i])) + 1));
			}else map.put(chars[i],"1");
		}
		int num = 0;
		for (Map.Entry<Character, String> entry : map.entrySet()) {
			num++;
			if (!entry.getValue().equals("1")){
				num += entry.getValue().toCharArray().length ;
			}
		}
		return num;
	}
