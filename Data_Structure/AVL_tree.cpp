#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
//	AVL树 结点结构体定义 
typedef int ElementType;
typedef struct TreeNode{
	ElementType val;
	TreeNode*  left;
	TreeNode* right;
	int bf;		//	平衡因子 = 左子树高度 - 右子树高度，只可能是-1,0,1 
	int height;	//	树高
	//	构造函数 
	TreeNode(ElementType x):val(x), left(nullptr), right(nullptr)
		, bf(0), height(0){}			
}*AVLTree;

int getHeight(TreeNode* t)
{
	return ( t==nullptr ? -1:t->height );
}
 
void reHeight_Bf(AVLTree root)
{
	//	按我们学校教材规定，空树的树高为 -1	
	int hl = getHeight(root->left);
	int hr = getHeight(root->right);
	//	更新树高、平衡因子 
	root->height =  max(hl, hr) + 1;
	root->bf = hl - hr;		 
}