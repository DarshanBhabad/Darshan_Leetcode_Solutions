class Solution {
public:
void BF(int src,vector<vector<pair<int,int>>>&G,int n,int dest,int k,vector<int>&distance){


  for(int i=0;i<=k;i++){//minimum dist with at most k stops i.e at most K+1 edges in betn so <=k



  vector<int> temp = distance; 
 // Directly changing distance causes a single Bellman-Ford iteration to use multiple edges, instead of exactly one additional edge.
  // 0 -> 1 -> 2  During the same iteration  distance[1] = distance[0] + w 
  // distance[2] = distance[1] + w  so two edge s during sam eiteration if we directly use dist so we use temp for each iteration // so each iteration it will have at most i+1 edges in betn
    for(int u=0;u<n;u++){
        if(distance[u] == INT_MAX) continue; // we havent found route to u yest so how we can go to its neigh from him
        for(int j=0;j<G[u].size();j++){ //for each edge
        int v = G[u][j].first;
        int wt = G[u][j].second;
            if(temp[v] > distance[u] + wt) { //edge relaxation
                    temp[v] = distance[u] + wt;
                }  
        }
        
    }
    distance=temp;
  }

return;
}
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //it is an directed graph as we only give flights from i to j and not necessary j to i
        //we have to find minmum path cost with at most  k stops (intermediate nodes)
  // we hav eto find min path cost from src to dest - use dijktras algo as wt(price) is also positive
// also bellaman ford  will ensure to have less than k nodes 
// as its first iteration only does that thing  
    
    //build graph 
   
    vector<vector<pair<int,int>>>G(n);
    //directed graph 
    for(auto f:flights){
        G[f[0]].push_back({f[1],f[2]});//neighbour v , wt


    }
    //call bf 
    vector<int>distance(n,INT_MAX);
    distance[src]=0;
    BF(src,G,n,dst,k,distance);
  if(distance[dst]<INT_MAX) return distance[dst];
  return -1;
        
    }
};