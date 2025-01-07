// Problem specs at https://leetcode.com/problems/cousins-in-binary-tree-ii/
// Solution beats 100% in runtime (<1ms), 33.76% in memory usage (11.66MB)

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        std::set<string> substringWords;

        for(int i = 0; i < words.size(); i ++) {
            for(int j = i+1; j < words.size(); j ++) {
                std::size_t hasWord = words[j].find(words[i]);
                if(hasWord != std::string::npos) {
                    substringWords.insert(words[i]);
                    break;
                }
            }
        }

        vector<string> returnValue;

        for(string s : substringWords) {
            returnValue.push_back(s);
        }

        return returnValue;
    }
};