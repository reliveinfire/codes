#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
		TrieNode* root = new TrieNode();
		for (string s : words)
			insert(root, s);
		vector<string> res;
		vector<vector<int>> visited(board.size(), vector<int>(board[0].size(),0));
		for (int i = 0 ; i < board.size() ; i++){
			for (int j = 0 ; j < board[0].size() ; j++){
				if (root->next[board[i][j]-'a']!=NULL){
				visited[i][j] = 1;
				dfs(i,j, "", root->next[board[i][j]-'a'], board, visited, res);
				visited[i][j] = 0;
				}
			}
		}
		return res;
        }
	private:
	struct TrieNode{
		int word;
		TrieNode* next[26];
		TrieNode()
		{
			word = 0;
			for (int i = 0 ; i < 26 ; i++)
				next[i] = NULL;
		}
	};
	void dfs(int row, int col, string ss, TrieNode* idx, vector<vector<char>>& board, vector<vector<int>>& visited, vector<string>& res)
	{
		ss += board[row][col];
		if (idx->word){
			idx->word=0;
			res.push_back(ss);
		}

		int dict[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
		for (int dd = 0 ; dd < 4 ; dd++){
			int nr = row + dict[dd][0];
			int nc = col + dict[dd][1];
			if (nr<0 || nr>=board.size() || nc<0 || nc>=board[0].size() || visited[nr][nc])
				continue;
			else {
				char cc = board[nr][nc];
				if (idx->next[cc-'a']!=NULL){
					visited[nr][nc]=1;
					dfs(nr,nc, ss, idx->next[cc-'a'], board, visited, res);
					visited[nr][nc]=0;
				}
			}
		}
		return;
	}
	void insert(TrieNode* root, string str){
		TrieNode* idx = root;
		for (char cc : str){
			if (idx->next[cc-'a']==NULL){
				idx->next[cc-'a'] = new TrieNode();
			}
			idx = idx->next[cc-'a'];
		}
		idx->word++;
		return;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<string> words = {"oath","pea","eat","rain"};
	vector<vector<char>> board= {
				{'o','a','a','n'},
				{'e','t','a','e'},
				{'i','h','k','r'},
				{'i','f','l','v'}
				};
	Solution sol;
	auto ret_vec = sol.findWords(board, words);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
