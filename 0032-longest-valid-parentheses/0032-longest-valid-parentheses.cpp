class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.size();

        stack<int> st;
        st.push(-1);
        // only to calculate 1st ()
// We push -1 initially as a boundary index. After popping the index of '(', -1 remains at the top, allowing us to calculate the length of "()" as 1 - (-1) = 2.
// as if we disnt push -1 1st and we get 1st () then for ) we pop ( so top becomes non accebile 
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i); //push index
            }
            else {
                st.pop();

                if(st.empty()) {
                    st.push(i); 
                    // track last index before starting the new substring
                    //tells us that new substring is started so it acts as starting point

                }
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};