// LeetCode -> 2096. Step-By-Step Directions From a Binary Tree Node to Another


// MLE
// BFS + map to parent
class Solution {
public:
    void mapToParent(TreeNode* node, TreeNode* parent, unordered_map<int, TreeNode*>& map_parent, TreeNode* &start, int startValue) {
        if(node == NULL)
            return;

        map_parent[node -> val] = parent;
        if(node -> val == startValue)
            start = node;

        mapToParent(node -> left, node, map_parent, start, startValue);
        mapToParent(node -> right, node, map_parent, start, startValue);
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<int, TreeNode*> map_parent;
        unordered_map<int, int> vis;
        queue<pair<TreeNode*, string>> q;
        TreeNode* start = NULL;
        mapToParent(root, NULL, map_parent, start, startValue);

        if(start == NULL) {
            //cout << "start is NULL" << endl;
            return "";
        }

        q.push({start, ""});
        vis[start -> val] = 1;

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();

                TreeNode* node= p.first;
                string str = p.second;

                if(node -> val == destValue){
                    // cout << node -> val << " " << destValue << endl;
                    // cout << str << endl;
                    return str;
                }

                if(node -> left != NULL && !vis[node -> left -> val]) {
                    //cout << str+'L' << endl;
                    q.push({node -> left, str+'L'});
                    vis[node -> left -> val] = 1;
                }

                if(node -> right != NULL && !vis[node -> right -> val]) {
                    //cout << str+'R' << endl;
                    q.push({node -> right, str+'R'});
                    vis[node -> right -> val] = 1;
                }

                if(map_parent[node -> val] != NULL && !vis[map_parent[node -> val] -> val]) {
                    //cout << str+'U' << endl;
                    q.push({map_parent[node -> val], str+'U'});
                    vis[map_parent[node -> val] -> val] = 1;
                }
            }
        }

        //cout << "Queue is empty" << endl;
        return "";
    }
};




// Approach-1 (Using LCA)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int src, int dest) {
        if (!root)
            return NULL;

        if (root->val == src || root->val == dest)
            return root;

        TreeNode* l = lowestCommonAncestor(root->left, src, dest);
        TreeNode* r = lowestCommonAncestor(root->right, src, dest);

        if (l && r)
            return root;

        return l ? l : r;
    }

    bool findPath(TreeNode* LCA, int target, string& path) {
        if (LCA == NULL) {
            return false;
        }

        if (LCA->val == target) {
            return true;
        }

        // explore Left
        path.push_back('L');
        if (findPath(LCA->left, target, path) == true) {
            return true;
        }

        path.pop_back();

        // explore right
        path.push_back('R');
        if (findPath(LCA->right, target, path) == true) {
            return true;
        }

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);

        string lcaTOSrc = "";
        string lcaTODest = "";

        findPath(LCA, startValue, lcaTOSrc);
        findPath(LCA, destValue, lcaTODest);

        string result = "";

        for (int i = 0; i < lcaTOSrc.length(); i++) {
            result.push_back('U');
        }

        result += lcaTODest;

        return result;
    }
};




// Approach-2 (Without finding LCA)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    bool findPath(TreeNode* LCA, int target, string& path) {
        if (LCA == NULL) {
            return false;
        }

        if (LCA->val == target) {
            return true;
        }

        // explore Left
        path.push_back('L');
        if (findPath(LCA->left, target, path) == true) {
            return true;
        }

        path.pop_back();

        // explore right
        path.push_back('R');
        if (findPath(LCA->right, target, path) == true) {
            return true;
        }

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        string rootToSrc = "";
        string rootToDst = "";

        findPath(root, startValue, rootToSrc); // O(n)
        findPath(root, destValue, rootToDst);  // O(n)

        int l = 0; // commonPathLength
        while (l < rootToSrc.length() && l < rootToDst.length() &&
               rootToSrc[l] == rootToDst[l]) {
            l++;
        }

        string result = "";
        // Add "U"
        for (int i = 0; i < rootToSrc.length() - l; i++) {
            result.push_back('U');
        }

        for (int i = l; i < rootToDst.length(); i++) {
            result.push_back(rootToDst[i]);
        }

        return result;
    }
};