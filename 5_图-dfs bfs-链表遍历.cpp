/* tree 
                      A
                    /   \
                   B     C
                 /  \   /  \     
                D   E   F   G
������ȱ���(DFS) : A B D E C F G
������ȱ���(BFS) : A B C D E F G
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//������ȱ���(DFS) + stack
//�������.   ָ�����-> 
void depthFirstSearch(TreeNode* root){
	stack<TreeNode*> nodeStack;  //ʹ��C++��STL��׼ģ���
	nodeStack.push(root);
	TreeNode *node;
	while (!nodeStack.empty()){
		node = nodeStack.top();
		cout << node->val;
		nodeStack.pop();
		if (node->right){
			nodeStack.push(node->right);  //�Ƚ�������ѹջ
		}
		if (node->left){
			nodeStack.push(node->left);  //�ٽ�������ѹջ
		}
	}
}

//DFS �ݹ�ʵ��
void dfs(TreeNode* root)
{
	if (root){
		cout << root->val;
		dfs(root->left);
		dfs(root->right);
	}
}

//������ȱ���(BFS) + queue
void breadthFirstSearch(TreeNode* root){
	queue<TreeNode*> nodeQueue;  //ʹ��C++��STL��׼ģ���
	nodeQueue.push(root);
	TreeNode *node;
	while (!nodeQueue.empty()){
		node = nodeQueue.front();
		nodeQueue.pop();
		cout << node->val;
		if (node->left){
			nodeQueue.push(node->left);  //�Ƚ����������
		}
		if (node->right){
			nodeQueue.push(node->right);  //�ٽ����������
		}
	}
}

