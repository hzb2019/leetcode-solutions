// Problem specs at https://leetcode.com/problems/word-subsets
// Solution beats 5.02% in runtime (542ms) and 5.02% in memory usage (259.97MB)

class Solution {
public:
    vector<string> wordSubsets(const vector<string>& words1, const vector<string>& words2) {
        std::vector<std::map<char, int>> words1LetterCounts;
        std::map<char, int> words2LetterCounts;

        for(const string& word : words2) {
            std::map<char, int> wordLetterCount;
            for(char ch : word) {
                wordLetterCount[ch] ++;
            }

            for(const std::pair<char, int> p : wordLetterCount) {
                words2LetterCounts[p.first] = std::max(p.second, words2LetterCounts[p.first]);
            }
        }

        for(const string& word : words1) {
            std::map<char, int> letterCount;
            for(char ch : word) {
                letterCount[ch] ++;
            }
            words1LetterCounts.push_back(letterCount);
        }

        vector<string> returnValue;

        int index = 0;
        for(std::map<char, int>& words1LetterCount : words1LetterCounts) {
            bool isUniversal = true;
            for(const std::pair<char, int>& p : words2LetterCounts) {
                if(words1LetterCount[p.first] < p.second) {
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal) returnValue.push_back(words1[index]);
            index ++;
        }

        return returnValue;
    }
};