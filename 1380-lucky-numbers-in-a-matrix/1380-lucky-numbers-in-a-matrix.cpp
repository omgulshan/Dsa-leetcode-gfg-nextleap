class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        // Create vectors to store the minimum values in each row and maximum values in each column
        vector<int> minInRows(matrix.size(), INT_MAX);
        vector<int> maxInCols(matrix[0].size(), INT_MIN);
        
        // Find the minimum values in each row and maximum values in each column
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                minInRows[i] = min(minInRows[i], matrix[i][j]);
                maxInCols[j] = max(maxInCols[j], matrix[i][j]);
            }
        }
        
        // Check if a number is both minimum in its row and maximum in its column
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == minInRows[i] && matrix[i][j] == maxInCols[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        
        return ans;
    }
};
