// LeetCode -> 988. Smallest String Starting From Leaf


class Solution {
public:

    void solve(TreeNode* node, string temp, string &ans){
        if(node == NULL)
            return ;

        temp += 'a' + node -> val ;

        if(node -> left == NULL && node -> right == NULL){
            reverse(temp.begin(), temp.end()) ;
            
            if(ans.empty() || temp < ans){
                //cout <<"Entered" << endl ;
                ans = temp ;
            }
            return ;
        }

        solve(node -> left, temp, ans) ;
        solve(node -> right, temp, ans) ;
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "" ;
        solve(root, "", ans) ;
        return ans ;
    }
};