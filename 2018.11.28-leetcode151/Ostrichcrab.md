```
class Solution {
public:
    void reverseWords(string &s) {
        s.insert(0,1,' ');
        reverse(s.begin(),s.end());
        int len = s.size();
        int now = 0;
        int pos = 0;
        int sum = 0;
        while(now < len){
            
            if(s[now]!=' '){
                now++;
                sum++;
            }else{
                
                if(sum != 0){
                    reverse(s.begin()+pos,s.begin()+pos+sum);
                    now++;
                    while(now<len&&s[now]==' ')s.erase(s.begin()+now);
                    pos=now;
                    sum=0;
                }else{
                    s.erase(s.begin()+now);    
                }
                
                
            }   
            
        }
        s.pop_back();
        
    }
};
```
