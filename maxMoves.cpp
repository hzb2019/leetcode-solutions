// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
// Solution beats 9.76% in runtime (95ms) and 7.56% in memory usage (91.29MB)

// This solution uses a DFT function to traverse the grid with a
// max runtime of O(m * (n - 1)) and a minimum runtime of Ω(n).

class Solution {
private:
    int mM;
    int mN;

    vector<vector<int>> mGrid;
    set<int> mVisited;

    int traverseGrid(int coordinate) {
        int x = coordinate % mN;
        int y = coordinate / mN;

        if(x + 1 >= mN || mVisited.find(coordinate) != mVisited.end()) return x;

        int maxValue = x;

        if(y + 1 < mM && mGrid[y][x] < mGrid[y + 1][x + 1]) {
            maxValue = std::max(maxValue, traverseGrid(coordinate + 1 + mN));
        }

        if(mGrid[y][x] < mGrid[y][x + 1]) maxValue = std::max(maxValue, traverseGrid(coordinate + 1));

        if(y - 1 >= 0 && mGrid[y][x] < mGrid[y - 1][x + 1]) {
            maxValue = std::max(maxValue, traverseGrid(coordinate + 1 - mN));
        }

        mVisited.insert(coordinate);
        return maxValue;
    }
    
public:
    int maxMoves(vector<vector<int>>& grid) {
        mM = grid.size();
        mN = grid[0].size();
        mGrid = grid;

        int maxMoves = 0;

        for(int i = 0; i < mM; i ++) {
            maxMoves = std::max(maxMoves, traverseGrid(i * mN));
            if(maxMoves == mN) break;
        }

        return maxMoves;
    }
};