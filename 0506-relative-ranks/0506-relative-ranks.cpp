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
            }
};