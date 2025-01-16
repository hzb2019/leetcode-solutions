// Problem specs at https://leetcode.com/problems/minimize-xor
// Solution beats 100% in runtime (<1ms) and 5.14% in memory usage (8.38MB)

class Solution {
public:
    int countBitsInNum(int num) {
        int numBytes = 0;
        while(num > 0) {
            if(num % 2 == 1) {
                numBytes ++;
            }
            num /= 2;
        }
        return numBytes;
    }

    vector<bool> getBitsFromInt(int num) {
        vector<bool> bitsVector;

        while(num > 0) {
            bitsVector.push_back(num % 2);
            num /= 2;
        }

        return bitsVector;
    }

    vector<bool> getXorBitVector(const vector<bool>& bitsInNum1, int numBitsInXor) {
        vector<bool> xorBitVector = vector<bool>(bitsInNum1.size(), 0);

        for(int i = bitsInNum1.size() - 1; i > -1 && numBitsInXor > 0; i --) {
            if(bitsInNum1[i] == 1) {
                xorBitVector[i] = true;
                numBitsInXor --;
            }
        }

        if(numBitsInXor > 0) {
            for(int i = 0; i < xorBitVector.size() && numBitsInXor > 0; i ++) {
                if(xorBitVector[i] == 0) {
                    xorBitVector[i] = true;
                    numBitsInXor --;
                }
            }

            while(numBitsInXor > 0) {
                xorBitVector.push_back(true);
                numBitsInXor --;
            }
        }

        return xorBitVector;
    }

    int getMinimizedXorValue(int numToUnset, int numBitsInXor) {
        vector<bool> bitsInNum = getBitsFromInt(numToUnset); 
        vector<bool> xorValueBits = getXorBitVector(bitsInNum, numBitsInXor);

        int minimalXorValue = 0;
        int power = 0;
        for(int i : xorValueBits) {
            minimalXorValue += (i * pow(2, power));
            power ++;
        }

        return minimalXorValue;
    }

    int minimizeXor(int num1, int num2) {
        int bitsInNum2 = countBitsInNum(num2);

        return getMinimizedXorValue(num1, bitsInNum2);
    }
};