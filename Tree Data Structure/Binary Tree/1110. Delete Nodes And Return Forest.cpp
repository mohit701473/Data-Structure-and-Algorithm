// LeetCode -> 1110. Delete Nodes And Return Forest
https://leetcode.com/problems/delete-nodes-and-return-forest/description/


/*
Approch -> DFS (PostOrder Traversal) + Hash Table (set)

Intution -> Fisrt Observation => Suppsoe that aap tree pr traverse kr rhe h or and app
            nodes ko delete krte ja rhe ho 
                    1
                   / \
                  2   3
                 / \ / \
                4  5 6  7
            suppose aap ko 2 and 5 delete krna h and jub aap 2 pr pahunche to aap ne 2 
            ko delete kr diya now aap 5 pr nhi pahunch skte to es se bachen ke liye
            humesa niche se nodes ko delete krna start kre.

            Second Observation => Suppose that aap ne 5 ko delete kr diya to aap ko 2 ke 
            right ko NULL set krna hoga q ki 5 is deleted now to aap Jub bhi kisi node ko
            delete kre to aap return m NULL send kr do jese ki 
            2 -> left = solve()
            2 -> right = solve()
            to jub aap 5 ko delete kr ke NULL send kroge to 2 ke right m NULL aa jayega 
            and Jub delete nhi krna ho to direct node return kr 4 ke case m direct node
            return kr do

            Third Observation => Koi bhi node teen type ka ho skta h leaf ndoe(0 child)
            node with only one child and mode with two child and jub leaf node ko delete
            karoge to kuch nhi pr jub node ke ek ya do child ho to suppose u r deleting
            ndoe = 2 then 4 and 5 ko ans vector m store krna hoga aapbcz ye ab new root
            or different tree/subtree root ki trh kam karenge

T.C. = O(N)
S.C. = O(N)
 */
class Solution {
public:
    TreeNode* solve(TreeNode* node, TreeNode* parent, vector<TreeNode*>& ans, unordered_set<int>& st) {
        if(node == NULL)
            return NULL;

        node -> left  = solve(node -> left, node, ans, st);
        node -> right = solve(node -> right, node, ans, st);

        if(st.find(node -> val) != st.end()) {
            if(node -> left != NULL)
                ans.push_back(node -> left);
            if(node -> right != NULL)
                ans.push_back(node -> right);
            
            return NULL;
        }

        return node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        vector<TreeNode*> ans;

        for(auto &it: to_delete) {
            st.insert(it);
        }

        if(solve(root, NULL, ans, st) != NULL) {
            ans.push_back(root);
        }

        return ans;
    }
};



