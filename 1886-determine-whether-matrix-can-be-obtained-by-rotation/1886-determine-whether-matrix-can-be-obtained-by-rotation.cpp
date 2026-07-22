class Solution {
public:
    // mat ko ek baar 90 degree clockwise rotate karke return karta hai
    vector<vector<int>> rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> rotated(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[i][j] = mat[n-1-j][i];
            }
        }

        return rotated;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // 4 possible states check karo: 0, 90, 180, 270 degree
        for (int turn = 0; turn < 4; turn++) {
            if (mat == target) return true;  // C++ mein vector<vector<int>> directly compare ho sakta hai
            mat = rotate(mat);  // agla rotation apply karo
        }

        return false;
    }
};