// Problem specs at https://leetcode.com/problems/move-pieces-to-obtain-a-string
// Solution beats 32.8% in runtime (<24ms) and 99.55% in memory usage (18.88MB)

class Solution {
public:
    bool verifyLetterCounts(std::string& start, std::string& target) {
        // {character : frequency}
        std::map<char, int> startMap;

        for(char ch : start) {
            startMap[ch] ++;
        }

        for(char ch : target) {
            startMap[ch] --;
        }

        for(auto p : startMap) {
            // p.second is the frequency value, when the difference is not
            // equal to zero, the frequency of characters is different so
            // the letter count is not the same between the strings
            if(p.second != 0) return false;
        }
        
        return true;
    }

    void swapLetters(std::string& start, int leftIndex, int rightIndex) {
        char ch = start[leftIndex];
        start[leftIndex] = start[rightIndex];
        start[rightIndex] = ch;
    }

    int findNextLeftIndex(std::string& start, int currentLeftIndex, int i) {
        // make sure currentLeftIndex is starting at the deepest
        // possible index so it doesn't have to repeat going over
        // blank indexes
        currentLeftIndex = std::max(currentLeftIndex, i);

        while(currentLeftIndex < start.length()) {
            // R blocking movement of next L, return false
            if(start[currentLeftIndex] == 'R') {
                // setting the index to this makes canSwapPositions return false
                currentLeftIndex = start.length();
                break;
            }
            if(start[currentLeftIndex] == 'L') {
                swapLetters(start, i, currentLeftIndex);
                break;
            }
            currentLeftIndex ++;
        }

        return currentLeftIndex;
    }

    int findNextRightIndex(std::string& start, int currentRightIndex, int i) {
        // make sure currentRightIndex is starting at the shallowest
        // possible index so it doesn't have to repeat going over
        // blank indexes
        currentRightIndex = std::min(i, currentRightIndex);
        while(currentRightIndex > -1) {
            // L blocking movement of next R, return false
            if(start[currentRightIndex] == 'L') {
                // setting index to this makes canSwapPositions return false
                currentRightIndex = -1;
                break;
            }
            if(start[currentRightIndex] == 'R') {
                swapLetters(start, i, currentRightIndex);
                break;
            }
            currentRightIndex --;
        }

        return currentRightIndex;
    }

    bool canSwapPositions(std::string& start, std::string& target) {
        int currentLeftIndex = 0;

        for(int i = 0; i < target.length(); i ++) {
            char ch = target[i];

            if(ch == 'L') {
                currentLeftIndex = findNextLeftIndex(start, currentLeftIndex, i);
                
                // character was not found, return false
                if(currentLeftIndex == start.length()) return false;
            }
        }


        int currentRightIndex = target.length() - 1;

        for(int i = target.length() - 1; i >= 0; i --) {
            char ch = target[i];
            
            if(ch == 'R') {
                currentRightIndex = findNextRightIndex(start, currentRightIndex, i);

                // character not found, return false
                if(currentRightIndex == -1) return false;
            }
        }

        return true;
    }

    bool canChange(std::string& start, std::string& target) {
        return verifyLetterCounts(start, target) && canSwapPositions(start, target);
    }
};