class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int>s;
        int n=A.size();
        vector<int>c(n,0);
        for(int i=0;i<A.size();i++){
            int count;
            if(i>0){
                count=c[i-1];
            }
            else{
                count=0;
            }
            
            if(A[i]==B[i]){
               if(s.find(A[i])==s.end()) //not alrady found no need as ele are unique nut still
                    count++;

                s.insert(A[i]);
                c[i]=count;
            }
            else{
                if(s.find(A[i])!=s.end()){
                    count++;
                }
                if(s.find(B[i])!=s.end()){
                    count++;
                    // s.insert(B[i]);
                }
                
                  s.insert(A[i]);
                  s.insert(B[i]);
                
                c[i]=count;

            }
        }
        return c;
    }
};