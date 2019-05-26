/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
typedef struct TreeNode Node;
void _InOrder(Node* pRoot, int* pRes, int* index) {
	if (pRoot) {
		_InOrder(pRoot->left, pRes, index);
		pRes[*index] = pRoot->val;
		(*index)++;
		_InOrder(pRoot->right, pRes, index);
	}
}
int GetTreeSize(Node* pRoot) {
	if (pRoot == NULL)
		return 0;
	return GetTreeSize(pRoot->left) + GetTreeSize(pRoot->right) + 1;
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* pRes = (int*)malloc(sizeof(int)*(*returnSize));
	if (pRes == NULL) {
		assert(0);
		return;
	}
	int index = 0;
	_InOrder(root, pRes, &index);
	return pRes;
}

