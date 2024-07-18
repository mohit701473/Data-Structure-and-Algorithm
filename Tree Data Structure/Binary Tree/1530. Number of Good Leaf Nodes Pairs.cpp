// LeetCode -> 1530. Number of Good Leaf Nodes Pairs
https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/


/*
Approach -> DFS(postorder traversal) + Hashmap

Intution -> First Observation => kisi bhi do leaf nodes ke beech ka shortest path unke 
            LCA(Lowest Common Ancestors) ke base pr niakl skte hai

            Second Observation => jb tum leaf ndoe pr ho to vha se distance ko return kr
            do q ki jb tu kisi ancestor pr pahunchoge to tb tumhare pass left or right 
            leaf nodes kitne distance pr h pta rhega and tb tum left and right distance
            ke base pr dekh skte ho ki ky ye ek good leaf node pairs ban skta h ki nhi
            and tum hmesa ancestor pr hi check karoge to tum hamesa shortest path ko
            hi dekhoge

            Third Observation => Tumhe leaf node ki distance ke sath unka count bhi 
            return krna hoga q ki suppose that ki tum kisi ancestor pr ho or left se tume
            mila 1 and right se mila 2 i.e. left m 1 distance pr laef node h and right m
            2 distance pr leaf node h now jub tum es ancestor se return karoge to tumhe 
            ye return krna hoga ki {1+1 - 1} and {2+1 - 2} i.e. {2-1} & {3-1} mtlb
            2 distance niche 1 leaf node h and 3 distance niche 1 leaf ndoe h
            So use a hash map and return that according

            Forth Observation => Suppose left and right se 1-1 hash map aaya to hash map 
            m maximum 10-10 elements persent ho skte h q ki 1 <= distance <= 10
            So TLE bhi nhi aaye ga
            U can use a vector also bcz map 1 <= distance <= 10 and u can make indexes
            as distance and store count in them

T.C. = O(10 * 10 * N)
S.C. = O(N)
 */
class Solution {
public:
    unordered_map<int, int> solve(TreeNode* node, int distance, int& cnt) {
        if(node == NULL) {
            unordered_map<int, int> mp = {};
            return mp;
        }

        if(node -> left == NULL && node -> right == NULL) {
            unordered_map<int, int> mp;
            mp[1] = 1;
            return mp;
        }

        unordered_map<int, int> l = solve(node -> left, distance, cnt);
        unordered_map<int, int> r = solve(node -> right, distance, cnt);

        for(auto& it: l) {
            int min_dis = distance - it.first;
            for(int i = min_dis; i > 0; i--) {
                if(r.find(i) != r.end()) {
                    cnt += (it.second * r[i]);
                }
            }
        }

        unordered_map<int, int> n;

        for(auto& it: l) {
            if(it.first + 1 < distance) {
                n[it.first + 1] += it.second;
            }
        }

        for(auto& it: r) {
            if(it.first + 1 < distance) {
                n[it.first + 1] += it.second;
            }
        }

        return n;
    }

    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        solve(root, distance, cnt);
        return cnt;
    }
};


/*
Approch -> Convert tree into a undirected graph + BFS

Intution -> Hume leaf nodes ke bech ka distance nikal na h to hum kisi node se
            niche to ja skte h pr upar nhi to if tree is copnverted into
            undirected graph then hum kisi bhi direction m traverse kr skte hai

            Que -> How to convert a tree into a undirected graph
            => node se parent ki mapping kr va lo and ba aage ky undirected
            graph m convert krne ke bad
            Ek cheej or jub hum node to parent mapping karenge usi ke sath
            hum sabhi leaf nodes ko store ke lenge and now kisi ek leaf
            node ko pakdenge and uski sbhi leaf node ke sath distance nikal
            lenge agr distance is less then given distance then cnt++
            last me cnt/2 return kr denge q ki suppose 4 se 5 ki shortesr
            distance h to humne 4-5 ko cnt kr liya and 5-4 ko bh kr liya
            hoga count

            Que -> How to compute the shortest distance from leaf node to other
            laef node
            => BFS, hum leaf node se BFS traversal marenge and kisi level pr
            leaf node mil gya and level < given distance then it is our ans
            cnt++;
            to sbhi leaf node se BFS traversal mar denge

*/

// Approach-1 (Using Graph and BFS)
// T.C : O(n^2)
// S.C : O(n)
class Solution {
public:
    void makeGraph(TreeNode* root, TreeNode* prev,
                   unordered_map<TreeNode*, vector<TreeNode*>>& adj,
                   unordered_set<TreeNode*>& st) {

        if (root == NULL) {
            return;
        }

        if (root->left == NULL && root->right == NULL) { // LEAF NODE
            st.insert(root);
        }

        if (prev != NULL) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj; // Graph
        unordered_set<TreeNode*> st;                     // leaf nodes

        makeGraph(root, NULL, adj, st);

        int count = 0; // count of good node pairs

        for (auto& leaf : st) {

            // BFS hit karo and see if you can find another leaf nodes within
            // distance
            queue<TreeNode*> que;
            unordered_set<TreeNode*> visited;
            que.push(leaf);
            visited.insert(leaf);

            for (int level = 0; level <= distance;
                 level++) { // only go till level <= distance
                int size = que.size();
                while (size--) { // level processed
                    TreeNode* curr = que.front();
                    que.pop();

                    if (curr != leaf && st.count(curr)) {
                        count++;
                    }

                    for (auto& ngbr : adj[curr]) {
                        if (!visited.count(ngbr)) {
                            que.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return count / 2;
    }
};


