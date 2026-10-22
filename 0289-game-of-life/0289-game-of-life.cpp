class Solution {
public:
//TC+O(n=N*M) SC=O(n*m)
bool check(int r,int c,int n,int m){
    if(r<0||r>=n||c<0||c>=m) return false;
    return true;
}
    void gameOfLife(vector<vector<int>>& board) {
        //as we have to do simultaneously for every cell we can use boolear array and save state change changes to it and lettter afgain iterate and make those changes 
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>st(n,vector<bool>(m,false));
        //try=ue- state changes 

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //constant work of 8 negihbour check 
                //cnt live neighbours of current cell
                //only 1,3,4 cause change in current state 
                //ight neighbours
                int cnt=0; //cnt the lie neighbours as conditions depends o thsese 
               int dr[]={1,-1,-1,1,1,-1,0,0};
              int  dc[]={1,-1,1,-1,0,0,1,-1};
               for(int k=0;k<8;k++){
                  int nr=i+dr[k];
                  int nc=j+dc[k];
                  if(check(nr,nc,n,m) && board[nr][nc]==1) cnt++; //check will run first so no worries
               }
               if(board[i][j]==1){//live cell 
                 if(cnt<2 || cnt>3) st[i][j]=true;

               }
               else{ //dead cell
                    if(cnt==3) st[i][j]=true; // we didnt updated status directly beacuse everything is happning simultaneously and not after change to prreserve orginal baord across all cells
               }
            }
        }

for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(st[i][j]){ //chnage the state
                  if(board[i][j]==1) board[i][j]=0;
                  else board[i][j]=1; 
                }
            }
}
        return;
    }
};