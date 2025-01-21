// Problem specs at https://leetcode.com/problems/first-completely-painted-row-or-column/
// Solution beats 15.66% in runtime (211ms) and 62.05% in memory usage (165.99MB)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numCols = mat[0].size();
        int numRows = mat.size();

        vector<int> rows = vector<int>(numRows, numCols);
        vector<int> cols = vector<int>(numCols, numRows);

        map<int, pair<int, int>> matNumberToCoordinates;

        for(int row = 0; row < numRows; row ++) {
            for(int col = 0; col < numCols; col ++) {
                matNumberToCoordinates[mat[row][col]] = make_pair(row, col);
            }
        }

        for(int index = 0; index < arr.size(); index ++) {
            int i = arr[index];
            pair<int, int> coordinates = matNumberToCoordinates[i];
            int row = coordinates.first;
            int col = coordinates.second;

            rows[row] --;
            cols[col] --;
            if(rows[row] == 0 || cols[col] == 0) return index;
        }

        return -1;
    }
};