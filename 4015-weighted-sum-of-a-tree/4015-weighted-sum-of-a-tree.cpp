class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=nums.size();

        //CREATE TREE AND USE BFS
        //TC=O(n) as we visit all nodes in BFS only once

    vector<vector<int>>children(n);
        for(int i=1;i<n;i++){ // root won't have any cild
            children[parent[i]].push_back(i);
        } 

        // find depth of every node 
        vector<int>depth(n);
        depth[0]=1;
        //BFS
        queue<int>q;
        q.push(0);
        int h=1; // ht is a maximum depth
        while(!q.empty()){
            int u=q.front();
            q.pop();
            // int d=depth[u];

            for(int  c:children[u]){
                depth[c]=depth[u]+1;
                h=max(h, depth[c]);
                q.push(c);
                
            }
        }

       long long fwt=0;
        for(int i=0;i<n;i++){
            fwt+=1LL*nums[i]*(h-depth[i]+1); //1LL entire multiplication to happen in long long
            
            
        }
        




        //only one test case failed  last TC=O(n2)
        
// //ht is maximum depth;
//         int h=1;
//          //to find depth 
//         vector<int>depth(n,-2);
//         depth[0]=1;
//         int cnt;
//         int temp;
//         for(int i=1;i<n;i++){
//             cnt=1;
//             if(parent[i]==0) depth[i]=cnt+1;
//             else{
//                 temp=i;
                
//                 while(parent[temp]!=0){
                    
//                     temp=parent[temp];
//                     //cnt++;
//                     if(depth[temp]!=-2) {
//                         cnt+=depth[temp];
                        
//                         break;
//                             }
//                 }
//                 depth[i]=cnt;
//             }
//              h=max(depth[i],h);
//         }
// long long fwt=0;
//         for(int i=0;i<n;i++){
//             fwt+=1LL*nums[i]*(h-depth[i]+1); //1LL entire multiplication to happen in long long
            
            
//         }
//         return fwt;\

        return fwt;
    }
};