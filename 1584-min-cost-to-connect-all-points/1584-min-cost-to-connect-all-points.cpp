class Solution {
public:

int primemst(int v,vector<vector<pair<int,int>>>G){
    vector<bool>MST(v,false);
    //min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //in case of pair in priority queue it keeps elemnt at root acc to p.first if sma e thrn by p.second 
    int mincost=0;
    pq.push({0,0});
    while(!pq.empty()){
        auto p=pq.top();
        int wt=p.first;
        int u=p.second;
        pq.pop();
        if(!MST[u]){//not included vertex
          MST[u]=true;
          mincost+=wt;
          for(int i=0;i<G[u].size();i++){//for each neighbour
           //sequential pairs 
            int v=G[u][i].first;
            int wt=G[u][i].second; //G[u][i] in vector of G[u] ith pair
            if(!MST[v]) pq.push({wt,v});// not necessary as we check !MST[u] before updating wt but just an optimization;  if not written it will enter in pq gets pop and not added in wt



          }

        }

    }
    return mincost;
}
    int minCostConnectPoints(vector<vector<int>>& points) {

        // here we have to find teh minimum cost of the path 
        // i.e minimum spanning tree (tree containing ) // all vertices connnected , undirected  and weighted graph with minium path cost 
        // prims or kruskals // we will use prims 

        //BUILD THE GRAPH 
        int n=points.size();
        //pair(neighbour, edge wt)
        vector<vector<pair<int,int>>>G(n);
        int wt;
        for(int i=0;i<n;i++){//curr row i.e u
            for(int j=i+1;j<n;j++)// new neighbours

            {
                wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                G[i].push_back({j,wt});
                G[j].push_back({i,wt});

            } 
            } 

            //now use prims 
           return  primemst( n,G);


        

    }
};