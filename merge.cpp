// Problem specs at https://leetcode.com/problems/merge-intervals/
// Solution beats 90.62% in runtime (3ms), 31.11% in memory usage (23.96MB)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), 
            [](vector<int>& v1, vector<int>& v2) {
                return (v1[0] == v2[0]) ? v1[1] < v2[1] : v1[0] < v2[0];
        });

        vector<vector<int>> newIntervals;

        for(int i = 0; i < intervals.size(); i ++) {
            int startNumber = intervals[i][0];
            int endNumber = intervals[i][1];

            while(i < intervals.size() - 1 && endNumber >= intervals[i+1][0]) {
                endNumber = std::max(endNumber, intervals[i+1][1]);
                i ++;
            }
            
            newIntervals.push_back({startNumber, endNumber});
        }

        return newIntervals;
    }
};