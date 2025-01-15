// Problem specs at https://leetcode.com/problems/counting-words-with-a-given-prefix
// Solution beats 100% in runtime (<1ms) and 75.23% in memory usage (13.10MB)

class Solution {
public:
    int prefixCount(const vector<string>& words, const string& pref) {
        int count = 0;

        for(const string& word : words) {
            if(word.front() == pref.front()) {
                if(pref.compare(word.substr(0, pref.size())) == 0) count ++;
            }
        }

        return count;
    }
};