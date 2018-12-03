/*
  题目：
  给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
  
  案例:
  s = "leetcode"  返回 0.
  s = "loveleetcode",  返回 2.
 
  注意事项：您可以假定该字符串只包含小写字母。
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int len=s.size();
        if(len<=1){//长度为0返回-1，长度为1返回0
            return len-1;
        }
        
        //长度大于等于2时        
        int* p=new int[26]{0};    
        for(int i=0; i<=len-1; i++){//记录每个字母出现的次数            
            p[s[i]-'a']++;
        }
                 
        int ret_idx=-1; 
        for(int i=0; i<=len-1; i++){//找第一个出现次数为1的字母的索引
            if(p[s[i]-'a']!=1){            
                continue;             
            }
            ret_idx=i;
            break;
        }
        
        return ret_idx;
    }
};
