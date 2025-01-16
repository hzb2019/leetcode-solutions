// Problem specs at https://leetcode.com/problems/bitwise-xor-of-all-pairings
// Solution beats 5.28% in runtime (145ms) and 5.28% in memory usage (88.72MB)

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        std::map<int, long> valueCounts;

        size_t nums1Size = nums1.size();
        size_t nums2Size = nums2.size();

        for(int i : nums1) {
            valueCounts[i] += nums2Size;
        }

        for(int i : nums2) {
            valueCounts[i] += nums1Size;
        }

        int xorValue = 0;
        for(const std::pair<int, int>& p : valueCounts) {
            if(p.second % 2 == 1) xorValue ^= p.first;
        }
        

        return xorValue;
    }
};