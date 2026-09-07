class Solution {
public:
    int lengthOfLastWord(string s) {
      int n=s.length();
      int count=0;
      int j=n-1;
          // Skip trailing spaces
        while (j >= 0 && s[j] == ' ') {
            j--;
        }

        // Count last word
        while (j >= 0 && s[j] != ' ') {
            count++;
            j--;
        }
        return count;
    }
};