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
    int ans=0;

    void dfs(TreeNode* root, int &count, vector<int> &f){
        if(!root) return;

        int i=root->val;
        if(f[i]%2==0) count++;
        else count--;
        f[i]++;

        if(root->left==NULL && root->right==NULL){
            if(count<=1) ans++;
        }

        dfs(root->left,count,f);
        dfs(root->right,count,f);

        f[i]--;
        if(f[i]%2==0) count--;
        else count++;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> f(10,0);
        int count=0;

        dfs(root,count,f);
        return ans;
        
    }
};

// DFS, Backtracking
// O(n=nodes) O(h=height)

// using dfs to traverse all root to leaf path and parellely finding
// count of odd freq elements. Palindrome is only possible if this count is <= 1
// on every root we check, if prev freq of this element was odd, then count--
// as adding one will make it even, and opposite for even. On hitting a leaf node
// we increase ans if count is <= 1. Then backtrack as reset freq and count value 