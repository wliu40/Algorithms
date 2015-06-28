/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector< vector<int> >result;
        // if NULL root, return an empty 2-D vector
        if (root == NULL)
           return result;
           
        // if root is not NULL, push it to a queue
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *cur = root;//the current TreeNode under visiting
        int cnt = 1;//how many valid node at one level?
        int size; // a helper variable for the loop
        // push the vector level by level
        while(!q.empty())
        {
            vector<int> levelX;//initiate the vector at beginning
            size = cnt;
            cnt = 0;//reset the counter
            for(int i = 0; i < size; i++)
            {
                cur = q.front();
                levelX.push_back(cur->val);
                q.pop();
                //if cur has a left/right child, push it to the queue
                // and also, remember the cnt, for next loop use
                if (cur->left)
                {
                	q.push(cur->left);
                	cnt++;
    			}
    			if (cur->right)
                {
                	q.push(cur->right);
                	cnt++;
    			}
        	}
        	//push the levelX vector at the end of the for loop
            result.push_back(levelX);
        }
        return result;
    }
};
