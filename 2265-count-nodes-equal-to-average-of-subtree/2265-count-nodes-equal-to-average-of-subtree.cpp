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
public:
    using p=pair<int,int>;
    int ans;

    p solve(TreeNode* root){
        if(!root) return {0,0};

        p pLeft=solve(root->left);
        p pRight=solve(root->right);

        int sum = pLeft.first+pRight.first+root->val;
        int count = pLeft.second+pRight.second+1;

        if(sum/count == root->val) ans++;

        return {sum,count};
    }

    int averageOfSubtree(TreeNode* root) {
        ans=0;
        solve(root);
        return ans;
    }
};

// O(n) O(n)
// Recursion

// starting from bottom, for each node we are finding sum and count
// if curr avg==root->val ans++, then returning curr {sum,count} to upper node