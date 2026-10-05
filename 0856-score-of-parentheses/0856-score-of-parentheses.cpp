class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        int sum=0;
        for(char c:s){
            if(c=='(')
                st.push(0);
            else{
                int ins=st.top();
                st.pop();

                int score=(ins==0)?1:2*ins;
                st.top()+=score;
            }
        }
        return st.top();
    }
};