/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
int count = 0;
void solve(TreeNode* root,long long sum){
    if(root==NULL)return;
    if(root->val==sum)count++;
    solve(root->left,sum-(long long)root->val);
    solve(root->right,sum-(long long)root->val);
}
    int pathSum(TreeNode* root, int targetSum) {
        if (root) {
            solve(root, (long long)targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return count;
    }
};
