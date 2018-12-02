import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

public class leetcode890 {
	public static List<String> findAndReplacePattern(String[] words, String pattern){
		//定义一个ArrayList动态数组result，只不过里面存的值是String类型的
		List<String> result = new ArrayList<>();//注意 new List<String>();语法是错的
		char[] patternArray = pattern.toCharArray();
		//遍历String[]字符串数组words中的每个字符串
		for(int i=0; i<words.length; i++)
		{
			boolean flag = true;
			char[] wordArray = words[i].toCharArray();
			if(wordArray.length == patternArray.length)
			{
				HashMap<Character,Character> judge = new HashMap<>();//HashMap 1
				HashMap<Character,Character> judge2 = new HashMap<>();//HashMap 2
				for(int j=0; j<patternArray.length; j++)//j<pattern.length()
				{
					if(judge.containsKey(patternArray[j]) == false)
					{
						judge.put(patternArray[j], wordArray[j]);//不是wordArray[i]
						if(judge2.containsKey(wordArray[j]) == false)
						{
							judge2.put(wordArray[j], patternArray[j]);
						}
						else
						{
							if(judge2.get(wordArray[j]) != patternArray[j])
							{
								flag = false;
								break;
							}
						}
						
					}
					else
					{
						if(judge.get(patternArray[j]) != wordArray[j])
						{
							flag = false;
							break;
						}
					}
				}
			}
			if(flag)
			{
				result.add(words[i]);
			}
		}
		return result;
	}	
