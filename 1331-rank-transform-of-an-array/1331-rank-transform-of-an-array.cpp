class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        // unordered_map<int,int>m;
       vector<int>copy=arr;
       sort(copy.begin(),copy.end());
       unordered_map<int,int>m;
     int r=1;
       for(int i=0;i<n;i++){
        if(m.find(copy[i])==m.end()){
        //    already dont exist and also we need to maintains mall value 1st occurrrnece         m[arr[i]] //rank increase when we get greater distinct number
        m[copy[i]]=r++;
           
        }
       }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = m[arr[i]];
        }

        return arr;
       
    }
};