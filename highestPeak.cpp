// Problem specs at https://leetcode.com/problems/map-of-highest-peak
// Solution beats 5.00% in runtime (1283ms) and 10.34% in memory usage (227.18MB)

class Solution {
public:
    set<pair<int, int>> assignedCoordinates;
    vector<pair<int, int>> coordinatesToFillAtNextHeight;
    vector<vector<int>> heightAssignments;
    int m;
    int n;
    int height = 0;

    bool isValidCoordinate(int row, int col) {
        bool rowIsInBounds = row >= 0 && row < m;
        bool colIsInBounds = col >= 0 && col < n;
        bool isNotAlreadyAssigned = assignedCoordinates.find(make_pair(row, col)) == assignedCoordinates.end();

        return rowIsInBounds && colIsInBounds && isNotAlreadyAssigned;
    }

    void addAdjacentCoordinatesToNext(int row, int col) {
        if(isValidCoordinate(row - 1, col)) {
            coordinatesToFillAtNextHeight.push_back(make_pair(row - 1, col));
            assignedCoordinates.insert(make_pair(row - 1, col));
        }

        if(isValidCoordinate(row + 1, col)) {
            coordinatesToFillAtNextHeight.push_back(make_pair(row + 1, col));
            assignedCoordinates.insert(make_pair(row + 1, col));
        }

        if(isValidCoordinate(row, col - 1)) {
            coordinatesToFillAtNextHeight.push_back(make_pair(row, col - 1));
            assignedCoordinates.insert(make_pair(row, col - 1));
        }

        if(isValidCoordinate(row, col + 1)) {
            coordinatesToFillAtNextHeight.push_back(make_pair(row, col + 1));
            assignedCoordinates.insert(make_pair(row, col + 1));
        }
    }

    void assignCoordinates(int row, int col, int height) {
        heightAssignments[row][col] = height;
        addAdjacentCoordinatesToNext(row, col);
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m = isWater.size();
        n = isWater[0].size();

        heightAssignments = vector<vector<int>>(m, vector<int>(n, 0)); 

        for(int row = 0; row < m; row ++) {
            for(int col = 0; col < n; col ++) {
                if(isWater[row][col] == 1) {
                    coordinatesToFillAtNextHeight.push_back(make_pair(row, col));
                    assignedCoordinates.insert(make_pair(row, col));
                }
            }
        }

        while(coordinatesToFillAtNextHeight.size() != 0) {
            vector<pair<int, int>> coordinatesToFillAtCurrentHeight;
            coordinatesToFillAtCurrentHeight = coordinatesToFillAtNextHeight;

            coordinatesToFillAtNextHeight.clear();

            for(pair<int, int>& coordinate : coordinatesToFillAtCurrentHeight) {
                assignCoordinates(coordinate.first, coordinate.second, height);
            }
            
            height ++;
        }

        return heightAssignments;
    }
};