class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mini,max;
        max=nums[0];
       // mini=*min_eement(nums.begin(), nums.end());
        for(int i=0;i < nums.size();i++)
        {    mini=INT_MAX;
            for(int j=i;j<nums.size();j++){
                if(mini>nums[j]){
                    mini=nums[j];
                }
            }
            if(max < nums[i]){
                max=nums[i];
            }
            if((max-mini) <= k){
               return i;
            }        
        }
        // if(stable<=k) return indx;
        return -1;
    }
};