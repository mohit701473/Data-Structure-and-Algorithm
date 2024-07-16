// LeetCode -> 2196. Create Binary Tree From Descriptions
https://leetcode.com/problems/create-binary-tree-from-descriptions/


/*
Approach -> HashMap + Set

Intution -> Just do simulation means jesa kha h vesa kr do. Traverseon the descriptions vector
            and check is parent node is already created or not also same for child and jo jo 
            child honge vo tumhare kabhi bhi root nhi ho skte to sbhi child ko se m dal me
            insert kr do
*/
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, TreeNode*> nodeAddr;
        unordered_set<int> isChild;

        for(int i = 0; i < n; i++) {
            int pval = descriptions[i][0];
            int cval = descriptions[i][1];
            bool flag = descriptions[i][2];
            TreeNode* parent = NULL;
            TreeNode* child = NULL;

            if(nodeAddr.find(pval) == nodeAddr.end()) {
                parent = new TreeNode(pval);
                nodeAddr[pval] = parent;
            } else {
                parent = nodeAddr[pval] ;
            }

            if(nodeAddr.find(cval) == nodeAddr.end()) {
                child = new TreeNode(cval);
                nodeAddr[cval] = child;
            } else {
                child = nodeAddr[cval] ;
            }

            if(flag) {
                parent -> left = child;
            } else {
                parent -> right = child;
            }

            isChild.insert(cval);
        }

        for(auto it: nodeAddr) {
            if(isChild.find(it.first) == NULL)
                return nodeAddr[it.first];
        }

        return NULL;
    }
};