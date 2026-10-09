class Solution {
public:
    int minInsertions(string s) {
     //O(n) and O(1)
     int n = s.size();
        int open = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;  // keep count of open
            }
            else {
                // We need two closing brackets(consecutive) for every opening bracket
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; // consume the second ')'
                }
                else {
                    ans++; // insert the missing ')' if we dont have consecutive //track of close 
                }

                if (open > 0) {  // ex )) we have open =0 can cause -ve so check open >0
                    open--; // satisfiied for one open 
                }
                else {
                    ans++; // insert a missing '('  ex ))  needs one (
                }
            }
        }

        return ans + 2 * open;  // rem open should be close by 2 opens 
        

        //STACK APPROACH O(n) O(1)
        // int n=s.size();
        // int count=0;
        // stack<char>st;
        // for(int i=0;i<n;i++){
        //     if(s[i]=='(') st.push(s[i]);
        //     else if(s[i]==')'){
        //         if(i<n&&s[i+1]==')'){
        //             if(st.size()>0){
        //                 st.pop();
        //                 i++;
        //             }
        //             else if(st.size()==0){ ex. ))  need to add (
        //                 count+=1;
        //                 i++;
        //             }
        //         }
        //         else if(i<n&&s[i+1]!=')'){
        //                 if(st.size()>0){  //it has open as st.size()>0 but lack one close so count++
        //                count+=1;
        //                st.pop();
        //             }
        //             else if(st.size()==0){
        //                 count+=2;  // ex. )     needs both open and one close
        //             }
        //         }
        //     }

        // }
        // return count+2*st.size(); // 2*st.size() cause st contains ( that aint get popped so for each od them we need to insert 2 close ))
    }
};