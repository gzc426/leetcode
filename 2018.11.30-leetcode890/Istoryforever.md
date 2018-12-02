//Leetcode of 890
class Solution {
public:
    bool match(string str,string p){
    	map<char,char> m;
        for(int i=0;i<str.size();i++){
            map<char,char>::iterator iter=m.find(str[i]);
            if(iter==m.end()){
            	m[str[i]]=p[i];
                continue;
            }else{
                if(iter->second!=p[i])
                    return false;
            }
        }
        int seen[27];
        for(int i=0;i<27;i++)seen[i]=0;
        for(map<char,char>::iterator i=m.begin();i!=m.end();i++){
            if(!seen[i->second-'a']){
                seen[i->second-'a']=1;
            }else{
                return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)     {
        vector<string> res;
        for(vector<string>::iterator i=words.begin();i!=words.end();i++){
            
            if(match(*i,pattern)){
                res.push_back(*i);
            }
            
        }
        return res;
        
    }
};
