```
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto cmp=[](const pair<int,int>& p1,const pair<int,int>& p2)
        {return p1.first>p2.first||(p1.first==p2.first&&p1.second<p2.second);};
        sort(people.begin(),people.end(),cmp);
        vector<pair<int,int>> res;
        for(auto &p:people)
        {
            res.insert(res.begin()+p.second,p);
        }
        return res;
    }
};
```
