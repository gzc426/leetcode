public static String reverseWords(String input){

		String[] arr = input.trim().split("\\s+");//"\\s+"
		int len = arr.length;
		/*
		String[] result = new String[len];
		for (int i = 0;i<len;i++){
			result[len-1-i] = arr[i];
		}
		return Arrays.toString(result);//[blue, is, sky, the]
		*/
		StringBuilder sb = new StringBuilder();
		for (int i = 0;i<len;i++){
			sb.append(arr[len-1-i]);
			if (len == 1){
			}else if(i<len-1)
				sb.append(" ");
		}
		return sb.toString();
	}
