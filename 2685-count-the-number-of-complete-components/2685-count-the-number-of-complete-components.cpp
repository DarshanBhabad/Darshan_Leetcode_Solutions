class Solution {
public:

void dfs(int src,vector<list<int>>& v,vector<bool>& visited,vector<int>& component){
    visited[src]=true;
    component.push_back(src);
    for(int neigh:v[src]){ //for each neighbour
    if(!visited[neigh]){
       dfs(neigh, v, visited, component);
    }
    }

return ;
    
    
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //check that there exists a cycle
        //vectors of list to track  the neighbours
        vector<list<int>>v(n);
        for(auto c : edges){
            //now c will be the vector of size 2 comntaining neigh
            v[c[0]].push_back(c[1]);
            v[c[1]].push_back(c[0]);
        }

        vector<bool>visited(n,false);
        int cnt=0;
        //connected components having cycle 
        for(int i=0;i<n;i++){ // to expplore all disconnected graphs
            if(!visited[i]){
                // for every node of current component to be connected to every other node 
                //  if k components then there will be total k-1 edges  for every node of compo;
                //if src is 0 compo_of curr graph=0,1,2  and each 1 & 2 will have k-1=3-1=2 neigh/edge

                vector<int>component ; //to store all vertices of current graph 
                dfs(i,v,visited,component); 
                int k = component.size();
                bool complete = true;

                // every node must connect to other k-1 nodes
                for (int node : component) {
                    if (v[node].size() != k - 1) {
                        complete = false;
                        break;
                    }
                }

                if (complete)
                    cnt++;


            }

        }

        
return cnt;
        
    }
};