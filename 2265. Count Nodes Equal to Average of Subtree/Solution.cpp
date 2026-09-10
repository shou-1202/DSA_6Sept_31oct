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
    pair<int, int> helper(TreeNode* root, int& ans){
        if(!root){
            return {0, 0};
        }

        pair<int, int>left = helper(root->left, ans);
        pair<int, int> right = helper(root->right, ans);
        
        int average = (root->val + left.first + right.first)/(left.second+right.second+1);
       
        if(root->val == average){
            ans++;
        }
        return {(root->val + left.first + right.first), (left.second+right.second+1)};

    }
    int averageOfSubtree(TreeNode* root) {
        if(!root->left && !root->right)return 1;

        int ans = 0;
        helper(root, ans);
        return ans;


    }
};