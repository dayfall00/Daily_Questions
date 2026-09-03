// class Solution {
// public:
//     bool uniformArray(vector<int>& nums1) {
//         int on,j; 
//         int minary;
//         minary=*min_element(nums1.begin(), nums1.end());
//         bool flag=true;
//         if(nums1[0]%2==0)
//         {
//             flag=0;
//         }
//         else {
//             on=nums1[0];
//             j=0;
//         }
//         int i=0, mini=INT_MAX;
//         while(i<nums1.size()){
//             if(nums1[i]%2!=0 && mini>nums1[i]){
//                 mini=nums1[i];
//                 j=i;
//             }
//             i++;
//         }
//         if(mini == INT_MAX)
//             return true;
//         on=mini;
//         if(minary%2){
//         for(int i=1;i<nums1.size();i++){
//             if(nums1[i]%2!=0){
//                 if(nums1[i] - nums1[j] >= 1)
//                     nums1[i]=nums1[i]-on;
//                 else
//                     return false;
//             }
//         }
//         }
//         else{
//         for(int i=1;i<nums1.size();i++){
//             if(nums1[i]%2==0){
//                 if(nums1[i] - nums1[j] >= 1)
//                     nums1[i]=nums1[i]-on;
//                 else
//                     return false;
//             }
//         }
//         }
//         return true;
//     }
// };


class Solution {
private:
    bool odd(int n)
    {
        return n%2!=0;
    }
public:
    bool uniformArray(vector<int>& nums1) {
        int on; 
        int minary;
        bool ne= false;
        minary=*min_element(nums1.begin(), nums1.end());
        int min=INT_MAX;
        if(odd(minary)){
            return true;
        }
        else{
            for(int i: nums1){
                if(odd(i)){
                    ne=1;
                }
            }
            if(ne){
                return false;
            }
            else{
                return true;
        }
        return true;
        }

    }
};