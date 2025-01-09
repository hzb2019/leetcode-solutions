// Problem specs at https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
// Solution beats 83.80% in runtime (12ms) and 64.10% in memory usage (157.49MB)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    std::deque<TreeNode*> mNodeDeque;

    long long getCurrentLevelSumAndNextLevel() {
        int nodeDequeSize = mNodeDeque.size();
        long long levelSum = 0;

        for(int i = 0; i < nodeDequeSize; i ++) {
            levelSum += mNodeDeque.front()->val;
            if(mNodeDeque.front()->left != nullptr) mNodeDeque.push_back(mNodeDeque.front()->left);
            if(mNodeDeque.front()->right != nullptr) mNodeDeque.push_back(mNodeDeque.front()->right);
            mNodeDeque.pop_front();
        }

        return levelSum;
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> levelSumsDescending;
        mNodeDeque.push_back(root);

        while(mNodeDeque.size() > 0) {
            levelSumsDescending.push(getCurrentLevelSumAndNextLevel());
        }

        if(levelSumsDescending.size() < k) return -1;

        long long returnValue = levelSumsDescending.top();

        while(k > 0) {
            returnValue = levelSumsDescending.top();
            levelSumsDescending.pop();
            k --;
        }

        return returnValue;
    }
};