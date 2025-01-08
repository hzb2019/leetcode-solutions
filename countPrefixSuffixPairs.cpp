// Problem specs at https://leetcode.com/problems/count-prefix-and-suffix-pairs-i
// Solution beats 100% in runtime (<1ms) and 30.51% in memory usage (24.16MB)

class Solution {
public:
    bool isPrefixAndSuffix(const string& s1, const string& s2) {
        bool isPrefix = 0 == s1.compare(s2.substr(0, s1.size()));
        bool isSuffix = 0 == s1.compare(s2.substr(s2.size() - s1.size()));
        return isPrefix && isSuffix;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;

        for(int i = 0; i < words.size(); i ++) {
            for(int j = i + 1; j < words.size(); j ++) {
                // keeping these two conditional continue statements in the for loop block
                // rather than the isPrefixAndSuffix function reduces runtime speed
                // from 4ms to <1ms by avoiding extra function calls
                if(words[i].size() > words[j].size()) continue;
                if(words[i].front() != words[j].front() || words[i].back() != words[j].back()) continue;
                if(isPrefixAndSuffix(words[i], words[j])) count ++;
            }
        }
        
        return count;
    }
};