class Solution {
public:
    int findMax(int row,int col,vector<vector<int>>& grid){
        int maxi = INT_MIN;
        for(int i=row;i<=row+2;i++){
            for(int j=col;j<=col+2;j++){
                maxi = max(maxi,grid[i][j]);
            }
        }
        return maxi;
    } 
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>res(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                res[i][j] = findMax(i,j,grid);
            }
        }
        return res;
    }
};
