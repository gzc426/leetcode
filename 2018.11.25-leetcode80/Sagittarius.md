class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        vector<int>::iterator it1,it2;
        it1=nums.begin();
        it2=nums.begin()+1;
        while(it2<nums.end())
        {
            if(*it1==*it2)
            {
                if((it2-it1)>1)
                    nums.erase(it2);
                else
                    it2++;
            }
            else
            {
                it1=it2;
                it2++;
            }
        }
        return nums.size();
    }
};
