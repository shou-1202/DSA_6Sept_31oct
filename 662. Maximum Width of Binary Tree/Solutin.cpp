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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>>q;
        TreeNode* curr = root;
        q.push({curr, 0});
        q.push({NULL, -1});

        long long i = 0, j = 0;
        long long maxWidth = 0;
        while(q.size()!=1){
            curr = q.front().first;
            if(curr!=NULL){
                j = q.front().second;
                maxWidth = max(maxWidth, j-i+1);
            }
            q.pop();
            if(curr == NULL){
                q.push({NULL, -1});
                i = q.front().second;
                continue;
            }
            if(curr->left){
                q.push({curr->left, 2*(j-i)+1});
            }
            if(curr->right){
                q.push({curr->right, 2*(j-i)+2});
            }
        }
        return maxWidth;
    }
};