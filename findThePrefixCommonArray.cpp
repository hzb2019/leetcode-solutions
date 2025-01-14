// Problem specs at https://leetcode.com/problems/word-subsets
// Solution beats 25.27% in runtime (19ms) and 11.02% in memory usage (91.13MB)

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        std::set<int> prefixA;
        std::set<int> prefixB;

        int commonPrefix = 0;
        vector<int> prefixArray;
        for(int i = 0; i < A.size(); i ++) {
            if(A[i] == B[i]) {
                commonPrefix ++;
                prefixArray.push_back(commonPrefix);
                continue;
            }

            prefixA.insert(A[i]);
            prefixB.insert(B[i]);

            bool BInPrefixA = (prefixA.find(B[i]) != prefixA.end());
            bool AInPrefixB = (prefixB.find(A[i]) != prefixB.end());
            
            if(BInPrefixA) {
                prefixA.erase(B[i]);
                commonPrefix ++;
            }

            if(AInPrefixB) {
                prefixB.erase(A[i]);
                commonPrefix ++;
            }

            prefixArray.push_back(commonPrefix);
        }

        return prefixArray;
    }
};