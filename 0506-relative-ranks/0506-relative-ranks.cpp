class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
    int n=score.size();
        map<int,int,greater<int>>m; //ordered map sorted numbers 
   vector<string>v(n);
   int cnt=0;
   for(int i=0;i<n;i++){
    m[score[i]]=i;
   }
        for(auto p:m){
            cnt++;
            if(cnt==1) v[p.second]="Gold Medal";
            else if(cnt==2) v[p.second]="Silver Medal";
            else if(cnt==3) v[p.second]="Bronze Medal";
            else v[p.second]= to_string(cnt);
       

        }
return v;

//using priority queue
//max heap
// class Solution {
// public:
//     vector<string> findRelativeRanks(vector<int>& score) {
//         vector<string> res(score.size());
//         std::priority_queue<pair<int, int>> maxHeap;
//         for (int i = 0; i < score.size(); i++){
//             maxHeap.push({score[i], i});
//         }
//         int r = 1;
//         while (!maxHeap.empty()){
//             auto [sc, idx] = maxHeap.top();
//             maxHeap.pop();
//             if (r == 1){
//                 res[idx] = "Gold Medal";
//             }else if (r == 2) {
//                 res[idx] = "Silver Medal";
//             }
//             else if (r == 3){
//                 res[idx] = "Bronze Medal";
//             }
//             else {
//                 res[idx] = to_string(r);
//             }
//             r++;
//         }
//         return res;
//     }
// };
            }
};