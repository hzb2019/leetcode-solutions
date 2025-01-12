// Problem specs at https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid
// Solution beats 76.90% in runtime (11ms) and 83.76% in memory usage (29.74MB)

class Solution {
public:
    bool canBeValid(string& s, string& locked) {
        if(s.size() % 2 != 0) return false;

        std::stack<int> availableIndices;
        std::stack<int> openBrackets;

        for(int i = 0; i < locked.size(); i ++) {
            if(locked[i] == '0') {
                availableIndices.push(i);
            } else if(s[i] == '(') {
                openBrackets.push(i);
            } else if(openBrackets.size() > 0) {
                openBrackets.pop();
            } else if (availableIndices.size() > 0) {
                availableIndices.pop();                   
            } else {
                return false;
            }
        }

        while(openBrackets.size() > 0 && availableIndices.size() > 0 &&
                openBrackets.top() < availableIndices.top()) {
                    openBrackets.pop();
                    availableIndices.pop();
                }

        return openBrackets.empty();
    }
};