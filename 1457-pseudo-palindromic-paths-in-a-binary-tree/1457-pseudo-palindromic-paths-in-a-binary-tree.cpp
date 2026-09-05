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