class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
//TC =One query → O(N)
//Q queries → O(Q × N)
        //Brute force 
       
        // int n=queries.size(); //rows
        // vector<int>ans(n,0);
        // //to track query number
        // int  idx=0; //1st query
        // for(auto p:queries){
        //     int i=p[0];
        //     int j=p[1];
        //    // int cnt=0;
        //    int cnt=0;
        //    int mcnt=0;
        //    // bool variable to track previous candle 
        //    bool prev=false;
        //    for(int k=i;k<=j;k++){
           
        //     if(s[k]=='|'){
        //         prev =true;
        //     }
        //     if(prev && s[k]=='*'){
        //         cnt++;
        //     }
        //     if(prev && s[k]=='|'){
        //      mcnt+=cnt;
        //      cnt=0;

        //    }
        // }
        // ans[idx]=mcnt;
        // idx++;
        // }
        // return ans;

      

 int n = s.size();

        // prefix[i] = number of plates (*) from index 0 to i
        vector<int> prefix(n, 0);

        if (s[0] == '*')
            prefix[0] = 1;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if (s[i] == '*')
                prefix[i]++;
        }

        // left[i] = nearest candle at or before i
        vector<int> left(n);
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') last = i;
                
            left[i] = last;
        }

        // right[i] = nearest candle at or after i
        vector<int> right(n);
        last = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|')
                last = i;
            right[i] = last;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = right[q[0]]; // first candle inside query including himself
            int r = left[q[1]];  // last candle inside query including himself

            if (l == -1 || r == -1 || l >= r) {
                ans.push_back(0);
            } else {
                ans.push_back(prefix[r] - prefix[l]);
            }
        }

        return ans;
    }
};