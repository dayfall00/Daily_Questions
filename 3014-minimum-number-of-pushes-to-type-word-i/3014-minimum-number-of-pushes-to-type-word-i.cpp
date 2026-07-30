class Solution {
public:
    int minimumPushes(string word) {
        int s= word.size();
        int cost=0;
        int r,q;
        q=s/8;
        r=s%8;
        int i=1;
        cost=(q*(q+1))*4+(q+1)*r;
        // for(;i<=q;i++)
        // {
        //     cost+=i*8;
        // }
        // cost+=(q+1)*r;
        return cost;

    }
};