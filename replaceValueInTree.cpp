// Problem specs at https://leetcode.com/problems/cousins-in-binary-tree-ii/
// Solution beats 84.20% in runtime (315ms), 10.40% in memory usage (374.26MB)

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
    vector<TreeNode*> mCurrentLayer;
    map<TreeNode*, int> mParentNodeToChildrenValueSum;
    map<TreeNode*, TreeNode*> mChildToParent;
    map<TreeNode*, TreeNode*> mParentNodes;

    bool isCousin(TreeNode* node1, TreeNode* node2) {
        return mParentNodes[node1] != mParentNodes[node2];
    }

    bool hasCousins() {
        bool cousinExists = false;

        for(int i = 1; i < mCurrentLayer.size() && i < 3; i ++) {
            cousinExists = isCousin(mCurrentLayer[0], mCurrentLayer[i]) || cousinExists;
        }

        return cousinExists;
    }

    int sumCurrentLayer() {
        int sum = 0;
        for(TreeNode* node : mCurrentLayer) {
            sum += node->val;
        }

        return sum;
    }

    void getNextLayerAndUpdateParentLayer() {
        int currentLayerSize = mCurrentLayer.size();
        int currentLayerSum = sumCurrentLayer();
        bool layerHasCousins = hasCousins();

        if(layerHasCousins) {
            for(int i = 0; i < currentLayerSize; i ++) {
                mCurrentLayer[i]->val = currentLayerSum - mParentNodeToChildrenValueSum[mParentNodes[mCurrentLayer[i]]];
            }
        } else {
            for(int i = 0; i < currentLayerSize; i ++) {
                mCurrentLayer[i]->val = 0;
            }
        }

        for(int i = 0; i < currentLayerSize; i ++) {
            if(mCurrentLayer[i]->left != nullptr) {
                mParentNodes[mCurrentLayer[i]->left] = mCurrentLayer[i];

                mParentNodeToChildrenValueSum[mCurrentLayer[i]] += (mCurrentLayer[i]->left->val);

                mCurrentLayer.push_back(mCurrentLayer[i]->left);
            }

            if(mCurrentLayer[i]->right != nullptr) {
                mParentNodes[mCurrentLayer[i]->right] = mCurrentLayer[i];

                mParentNodeToChildrenValueSum[mCurrentLayer[i]] += (mCurrentLayer[i]->right->val);

                mCurrentLayer.push_back(mCurrentLayer[i]->right);
            }
        }

        mCurrentLayer.assign(mCurrentLayer.begin() + currentLayerSize, mCurrentLayer.end());

    }

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        mCurrentLayer.push_back(root);

        while(mCurrentLayer.size() > 0) { 
            getNextLayerAndUpdateParentLayer();
        }

        return root;
    }
};