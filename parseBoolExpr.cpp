// Problem specs at https://leetcode.com/problems/parsing-a-boolean-expression/description/
// Solution beats 30.13% in runtime (9ms), and 11.52% in memory usage (12.98MB)


class Solution {
public:
    char evaluateExpression(char boolOp, vector<bool>& boolList) {
        bool returnValue = boolList[0];
        for(bool b : boolList) {
            if(boolOp == '|') returnValue |= b;
            else if(boolOp == '&') returnValue &= b;
            else if(boolOp == '!') returnValue = !returnValue;
        }
        return returnValue ? 't' : 'f';
    }

    void onCloseParentheses(stack<char>& calcStack) {
        vector<bool> boolList;

        while(isalpha(calcStack.top())) {
            if(calcStack.top() == 't') boolList.push_back(true);
            else if(calcStack.top() == 'f') boolList.push_back(false);
            calcStack.pop();
        }
        char boolOp = calcStack.top();
        calcStack.pop();
        calcStack.push(evaluateExpression(boolOp, boolList));
    }

    bool parseBoolExpr(string& expression) {
        stack<char> calcStack;

        for(char ch : expression) {
            if(ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|') calcStack.push(ch);
            else if(ch == ')') onCloseParentheses(calcStack);
        }
        
        return calcStack.top() == 't';
    }
};