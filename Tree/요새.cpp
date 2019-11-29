/*
algospot(id: fortress)
����� ������ Ʈ�������� �ٲٰ� ��� ������ �ִ� �Ÿ� ã�� 
�������� ���̴� �� �� �ϳ�
1. ���� �� ��Ʈ-�� ����� ����(����)
2. ���� �� ��-�� ����� ���� 
*/

struct TreeNode{
	vector<TreeNode*> children;
};

TreeNode* getTree(int root){
	TreeNode* ret = new TreeNode();
	for(int ch = 0; ch < n; ch++){
		if(isChild(root, ch))
			ret->children.push_back(getTree(ch));
	}
	return ret;
}

// ���ݱ��� ã�� ���� �� ��-�� ����� ���� 
int longest;
// root�� ��Ʈ�� �ϴ� ����Ʈ���� ���̸� ������ + longest ��� 
int height(TreeNode* root){
	vector<int> heights;
	for(int i = 0; i < root->children.size(); i++){
		heights.push_back(height(root->children[i));
	}
	if(heights.empty()) return 0;
	sort(heights.begin(), heights.end());
	
	// root�� �ֻ��� ���� �ϴ� ��θ� ���
	if(heights.size() >= 2){
		longest = max(longest, 2 + heights[heights.size()-2] + heights[heights.size()-1]);
	} 
	return heights.back() + 1;
}

int solve(TreeNode* root){
	longest = 0;
	int h = height(root);
	return max(h, longest);
}
