/*
algospot(id: fortress)
요새를 계층적 트리구조로 바꾸고 노드 사이의 최대 거리 찾기 
최장경로의 길이는 둘 중 하나
1. 가장 긴 루트-잎 경로의 길이(높이)
2. 가장 긴 잎-잎 경로의 길이 
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

// 지금까지 찾은 가장 긴 잎-잎 경로의 길이 
int longest;
// root를 루트로 하는 서브트리의 높이를 리턴함 + longest 계산 
int height(TreeNode* root){
	vector<int> heights;
	for(int i = 0; i < root->children.size(); i++){
		heights.push_back(height(root->children[i));
	}
	if(heights.empty()) return 0;
	sort(heights.begin(), heights.end());
	
	// root를 최상위 노드로 하는 경로를 고려
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
