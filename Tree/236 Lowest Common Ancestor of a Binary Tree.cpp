/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w 
as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, 
since a node can be a descendant of itself according to the LCA definition.
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
class Solution1 {
public:
    void find(TreeNode *root, TreeNode *des, vector<TreeNode*> &v)
    {
        //如果空，则返回
        if (!root)  return;
        //如果非空，则沿途压入vector  
        v.push_back(root);
        //如果找到了，则返回
        if ( root == des ) return;
        //递归查找左树和右树
        find(root->left, des, v);
        find(root->right, des, v);
        //如果vector的最后一个元素不是我们需要的，弹出
        if ( v[v.size() - 1] != des )  v.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       //vector v1记录了从根节点到p的路径
        vector<TreeNode*> v1;
        find(root, p, v1);
        //vector v2记录了从根节点到q的路径
        vector<TreeNode*> v2;
        find(root, q, v2);
        
        //找出v1和v2第一个不同的元素
        int i;
        for (i = 0; i < v1.size() && i < v2.size(); i++)
        {
            if (v1[i] != v2[i])
                return v1[i-1];
        }
        //如果一个vector穷尽了，依然都相同，则返回较短vector的最后那个元素
        return v1.size() < v2.size() ? v1[v1.size() - 1]:v2[v2.size() - 1];
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class solution2{
public:
    TreeNode* find(TreeNode *root,  TreeNode* p, TreeNode* q)
    {
        if( !root || root == p || root == q)  
            return root;
            
        TreeNode *left = find(root->left, p, q);
        TreeNode *right = find(root->right, p, q);
        
        if(left && right )   
            return root;
            
        if (left)
            return left;
        else
            return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root, p, q);
    }
};
