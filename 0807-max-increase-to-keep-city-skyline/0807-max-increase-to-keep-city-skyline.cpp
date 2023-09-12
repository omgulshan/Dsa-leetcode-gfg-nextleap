class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>rowMax;
        vector<int>colMax;
        int maxi = -1;
        for(int i = 0; i<grid.size(); i++){
            maxi = -1;
            for(int j = 0; j < grid.size(); j++){
                maxi = max(maxi, grid[i][j]);
            }
            rowMax.push_back(maxi);
        }
        for(int i = 0; i<grid.size(); i++){
            maxi = -1;
            for(int j = 0; j < grid.size(); j++){

                maxi = max(maxi, grid[j][i]);
            }
            colMax.push_back(maxi);
        }
        long long int sum = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                if(grid[i][j] >= rowMax[i] && grid[i][j] >= colMax[j]){
                    continue;
                }
                else{
                    if(rowMax[i] < colMax[j]){
                        sum += abs(grid[i][j]-rowMax[i]);
                    }
                    else
                        sum += abs(grid[i][j]-colMax[j]);
                }
            }
        }
        return sum;
    }
};