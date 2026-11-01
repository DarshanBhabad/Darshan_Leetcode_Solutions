class Solution {
public:
 void cg(int i , int j,int m , int n,vector<string>&ans){
    //BC 
    if(i==m-1 && j==n-1) {
        ans[i][j]='.';
        return;
    }
    ans[i][j]='.';
    if( check(i,j+1,m,n) )  cg(i,j+1,m,n,ans); //g0 right 
    else cg(i+1,j,m,n,ans); //go down as we reah right boundry 
    return;
   
 }
bool check(int i,int j,int m,int n){
     if(i>=0 && j>=0 && i<m && j<n)//valid grid cell
     return true;

     return false;
}
    vector<string> createGrid(int m, int n) {
        //right -right roght and  then left
        //recursion
        vector<string>ans(m,string(n,'#')); // ans vector initialized with nsize string #
        cg(0,0,m,n,ans);
        return ans;

        // vector<string> grid(m, string(n, '#'));
        // for (int i = 0; i < n; i++)
        //     grid[0][i] = '.'; //right
        // for (int i = 0; i < m; i++)
        //     grid[i][m - 1] = '.'; //down
        // return grid;
    }
};