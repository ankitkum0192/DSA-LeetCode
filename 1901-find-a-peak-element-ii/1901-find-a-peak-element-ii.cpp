class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows=mat.size();
        int coln=mat[0].size();
        int low=0;
        int high=coln-1;
        while(low<=high){
            int maxrow=0;
            int mid =(low+high)/2;
            for(int i=1;i<rows;i++){
                if(mat[i][mid]>mat[maxrow][mid])
                maxrow=i;   
            }
            int left=(mid-1>=0)?mat[maxrow][mid-1]:-1;
            int right=(mid+1<coln)?mat[maxrow][mid+1]:-1;
            if(mat[maxrow][mid]>left && mat[maxrow][mid]>right){
                return {maxrow,mid};
            }
            else if (left > mat[maxrow][mid])
                high = mid - 1;

            else
                low = mid + 1;
        }

        return {-1, -1};
        }
        
    
};