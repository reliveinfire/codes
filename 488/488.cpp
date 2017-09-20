#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int findMinStep(string board, string hand){
		unordered_map<char,int> hh;
		for (char c : hand)
			hh[c]++;
		int ret = dfs(board, hh);
		if (ret == INT_MAX)
			return -1;
		return ret;
        }
	int dfs(string board, unordered_map<char,int>& hh){
		int ret = INT_MAX;
		if (board.empty())
			return 0;
		int idx = 0;
		string tmp;
		while (idx < board.size()){
			char cc = board[idx];
//			cout << idx <<":"<<board <<":"<<cc << endl;
			if (idx + 2 < board.size() && cc ==board[idx+1] && cc == board[idx+2]){
				int i = 2;
				while(idx+i < board.size() && cc==board[idx+i])
					i++;
				tmp = board.substr(0,idx);
				if (idx+i<board.size())
					tmp += board.substr(idx+i);
				ret = min(ret, dfs(tmp, hh));
				idx += i;
			} else if (idx + 1 < board.size() && cc==board[idx+1]){
				if (hh.count(cc)!=0){
					//cout << "2 use" << cc<<endl;
					hh[cc]--;
					if (hh[cc]==0){
						hh.erase(cc);
					}
					tmp = board.substr(0, idx) + board.substr(idx+2);
					int rr = dfs(tmp, hh);
					if (rr!=INT_MAX)
						rr+= 1;
					ret = min(ret, rr);
					hh[cc]++;
				}
				idx = idx+2;
			} else {
				if (hh.count(cc)!=0 && hh[cc]>=2){
					//cout << "3 use" << cc<<endl;
					hh[cc] = hh[cc] - 2;
					if (hh[cc]==0){
						hh.erase(cc);
					}
					tmp = board.substr(0, idx) + board.substr(idx+1);
					int rr = dfs(tmp, hh);
					if (rr!=INT_MAX)
						rr+=2;
					ret = min(ret, rr);
					hh[cc] = hh[cc] + 2;
				}
				idx = idx +1;
			}
		}
		return ret;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	//ret = sol.findMinStep("WRRBBW", "RB");
	//ret = sol.findMinStep("WBBW", "RB");
	//ret = sol.findMinStep("RBYYBBRRB", "YRBGB");
	//ret = sol.findMinStep("RBBBRRB", "CCC");
	ret = sol.findMinStep("RWYWRRWRR", "YRY");
	cout << ret << "\n";


	return 0;
}
