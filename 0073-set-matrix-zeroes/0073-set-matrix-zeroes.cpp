class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();      // rows
        int m = matrix[0].size();   // columns
        
        vector<int> row(n, 0);
        vector<int> coln(m, 0);
        
        // Step 1: mark karo kaunse row/col mein 0 hai
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    coln[j] = 1;
                }
            }
        }
        
        // Step 2: marked row/col ko 0 se fill karo
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(row[i] == 1 || coln[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};