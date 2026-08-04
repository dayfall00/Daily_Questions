class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
     sort(nums.begin(), nums.end());
        vector<int> ans;
        int mins= nums[0];
        int maxs= nums[nums.size()-1];
        int i=0;
        while(mins<maxs)
        {
            while(mins<nums[i])
            {
                ans.push_back(mins++);
            }
            if(nums[i]==mins)
            {
                i++;
                mins++;
            }
        }
        return ans;
    }
};