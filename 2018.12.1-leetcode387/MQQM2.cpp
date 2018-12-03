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
        int ret_idx=-1;    
        
        for(int i=0; i<=len-1; i++){ 
            if(s[i]=='#'){
                continue;
            }
            
            int j=0;
            for(; j<=len-1; j++){
                if( i==j || s[j]=='#' ){
                    continue;
                }
                                           
                if(s[i]==s[j]){//s[i] is not unique 
                    char c=s[j];
                    for(int k=0; k<=len-1; k++){
                        if(c==s[k]){
                            s[k]='#';
                        }
                    }
                    break;//break for(j)
                }                
            }//end of for(j)   
            if(j==len){               
                ret_idx=i;
                break;
            }                                   
        }//end of for(i)    
        
        return ret_idx;
    }
};
