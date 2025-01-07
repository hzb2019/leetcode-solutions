// Problem specs at https://leetcode.com/problems/swap-nodes-in-pairs/
// Solution beats 100% in runtime (<1ms), 13.69% in memory usage (11.30MB)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;

        vector<ListNode*> nodes;
        vector<ListNode*> swappedNodes;

        while(head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }

        for(int i = 0; i < nodes.size() - 1; i += 2) {
            swappedNodes.push_back(nodes[i + 1]);
            swappedNodes.push_back(nodes[i]);
        }

        if(nodes.size() % 2 == 1) {
            swappedNodes.push_back(nodes.back());
        }

        for(int i = 0; i < swappedNodes.size() - 1; i ++) {
            swappedNodes[i]->next = swappedNodes[i+1];
        }

        swappedNodes.back()->next = nullptr;

        return swappedNodes[0];
    }
};