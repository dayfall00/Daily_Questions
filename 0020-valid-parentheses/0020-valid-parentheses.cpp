class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
       char a='(';
       char b= ')';
       char c= '{';
       char d= '}';
       char e= '[';
       char f= ']';
       st.push('a');
       for(auto x: s)
       {
        if(x==a||x==c||x==e)
            st.push(x);
        else if(x==b && st.top()==a)
        {
            st.pop();
        }
        else if(x==d && st.top()==c)
        {
            st.pop();
        }
        else if(x==f && st.top()==e)
        {
            st.pop();
        }
        else{
            return false;
        }

            
       }
    return st.top()=='a';
    }
};