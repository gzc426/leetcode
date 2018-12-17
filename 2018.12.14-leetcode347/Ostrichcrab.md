```
class Solution {
public:
    struct node
    {
        int val;
        int cnt;
        bool operator < (const node &t){
            return cnt>t.cnt;
        }
    }p[100004];
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size()==0) return res;
        sort(nums.begin(),nums.end());
        p[0].val = nums[0]; p[0].cnt = 0;
        int index = 0;
        for(int i = 1; i < nums.size(); i++){
            while(p[index].val == nums[i]){
                p[index].cnt++; i++;
            }
            index++;
            p[index].val = nums[i];
            p[index].cnt = 1;
        }
        sort(p,p+index+1);
        for(int i = 0; i < k; i++){
            res.push_back(p[i].val);
        }
        return res;
    }
};
```
