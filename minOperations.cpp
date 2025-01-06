// Problem specs at https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
// Solution beats 100% in runtime (<1ms), 25.33% in memory usage (12.52MB)

class Solution {
public:
    vector<int> minOperations(string& boxes) {
        if(boxes.size() == 1) return {0};

        int leftCount = 0;
        int rightCount = 0;
        int startDistance = 0;

        for(int i = 0; i < boxes.size(); i ++) {
            if(boxes[i] == '1') {
                rightCount ++;
                startDistance += i;
            }
        }

        vector<int> returnValue;
        int totalDistances = startDistance;

        for(int i = 0; i < boxes.size(); i ++) {
            if(boxes[i] == '1') rightCount --;
            
            returnValue.push_back(totalDistances);

            if(boxes[i] == '1') leftCount ++;

            totalDistances += leftCount;
            totalDistances -= rightCount;
        }
        
        return returnValue;
    }
};