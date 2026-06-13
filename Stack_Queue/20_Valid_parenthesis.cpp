/*
TC - O(N) - iterate through all chars in string
SC - O(N) - worst case when all chars are opening parenthesis
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else {
                if (st.empty()) return false;

                char top = st.top();

                if ((top == '(' && c == ')') ||
                    (top == '{' && c == '}') ||
                    (top == '[' && c == ']'))
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};