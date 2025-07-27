//T.C -> O(n^2)
//S.C -> O(1) 
//we have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
//make sure we DO NOT allocate another 2D matrix and do the rotation.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m =matrix.size();
        int n =m; // so it is a square matrix.
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++){
             reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
