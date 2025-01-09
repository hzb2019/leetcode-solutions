// Problem specs at https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/
// Solution beats 29.23% in runtime (361ms) and 30.27% in memory usage (163.6MB)

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        std::map<int, int> numsFrequency;

        for(int i : nums) {
            numsFrequency[i] ++;
        }

        vector<int> sortedNumsSet;

        for(auto& p : numsFrequency) {
            sortedNumsSet.push_back(p.first);
        }

        int maxBeauty = 0;
        int beauty = 0;

        int left = 0;
        int right = 0;

        while(true) {
            while(right < sortedNumsSet.size() && sortedNumsSet[right] <= sortedNumsSet[left] + (k * 2)) {
                beauty += numsFrequency[sortedNumsSet[right]];
                right ++;
            }

            maxBeauty = std::max(maxBeauty, beauty);
            if(right == sortedNumsSet.size()) break;

            beauty -= numsFrequency[sortedNumsSet[left]];
            left ++;
        }

        return maxBeauty;
    }
};