058_(最后一个单词的长度)Length of Last Word
1.1 问题描述
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指由字母组成，但不包含任何空格的字符串。
1.2 输入与输出
输入：
string s：仅包含大小写字母和空格 ' ' 的字符串 s
输出：
int：最后一个单词的长度
1.3 样例
1.3.1 样例1
输入: "Hello World"
输出: 5
1.3.2 样例2
输入: "Hello "
输出: 5

java版：
import java.util.Scanner;
public class Main{	
	public static void main(String[] args) {		
		Scanner in = new Scanner(System.in);		
		if(in.hasNext()) {			
			String[]strings words = in.nextLine().split(" ");
			System.out.println(words[words.length-1].length());			
		}else			
			System.out.println(0);
	}
}

python版：
class Solution:
    def lengthOfLastWord(self, s):       
        return len(s.strip(' ').split(' ')[-1])
//这个写法简单，因为字符串有一个方法是分割字符串方法split()，这里只要用空格将字符串分割然后返回
最后一个字符串的长度即可，另外要注意的是分割之前先用strip()方法将字符串最后的空格删除掉,否则会分割出一个空字符串在最后。
