// Problem specs at https://leetcode.com/problems/circular-sentence
// Solution beats 100% in runtime (<1ms) and 96.30% in memory usage (8.10MB)

class Solution {
public:

    /**
    *  compares last letter of each word in sentence to first letter of
    *  each following word in a circular manner
    *
    *  @param sentence  string without leading or trailing spaces of alpha
    *                   characters with spaces to separate words
    *  @return          false if the last letter of a word does not match the first 
    *                   letter of the following word, true otherwise
    */
    bool isCircularSentence(string& sentence) {
        char previousLetter = sentence[0];
        bool wasSpace = false;

        for(char ch : sentence) {
            if(wasSpace) {
                if(ch != previousLetter) return false;
                wasSpace = false;
            }
            
            if(ch != ' ') previousLetter = ch;
            else wasSpace = true;
        }

	// completes the circular check
        if(previousLetter != sentence[0]) return false;

        return true;
    }
};