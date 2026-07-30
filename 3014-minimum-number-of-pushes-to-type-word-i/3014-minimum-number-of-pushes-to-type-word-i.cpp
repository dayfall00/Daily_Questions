class Solution {
public:
    int minimumPushes(string word) {
        int s= word.size();
        int cost=0;
        int r,q;
        q=s/8;
        r=s%8;
        int i=1;
        for(;i<=q;i++)
        {
            cost+=i*8;
        }
        cost+=i*r;
        return cost;

    }
};