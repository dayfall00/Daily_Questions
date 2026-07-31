class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char x:word){
            freq[x-'a']++;
         
        }
        sort(freq.rbegin() , freq.rend());
        int cost=0;
        for(int i=0; i<26; i++){
            cost +=  freq[i] *(i/8 +1);
        }
        
        return cost;
    }
};