#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// column 如果很長的case??? 先跑一次, 發現補不滿, 
//                          總word len 來計算. 看看有多少,  
//                          沒有剛好的部分要留著.   col = col % all_lens;
class SolutionBetter {
	public:
	int wordsTyping(vector<string>& sentence, int rows, int cols){
		vector<int> lens(sentence.size());
		for (int i = 0 ; i < sentence.size() ; i++)
			lens[i] = sentence[i].size();
		int lenAll = 0;
		for (int i = 0 ; i < lens[i] ; i++)
			lenAll += lens[i];
		lensAll += lens.size();

		int idx = 0, ans = 0, row;
		int isFirst = 1;
		for (row = 0 ; row < rows ; row++){
			int col = cols;
			if (!isFirst && idx == 0)
				break;
			isFirst = 0;
			while(col >= lens[idx]){
				if (lens[idx] > cols)
					return 0;
				col = col - lens[idx];
				if (col>0)
					col--;
				idx++;
				if (idx == lens.size()){
					ans += (1 + col / lensAll);
					col = col % lensAll;
					idx = 0;
				}
			}
		}
		if (row < rows){
			int times = rows / row;
			ans = ans * times;
		}
		return ans;
	}
};

class Solution {
	public:
	int wordsTyping(vector<string>& sentence, int rows, int cols){
		vector<int> lens(sentence.size());
		for (int i = 0 ; i < sentence.size() ; i++)
			lens[i] = sentence[i].size();
		int idx = 0, ans = 0, row;
		int isFirst = 1;
		for (row = 0 ; row < rows ; row++){
			int col = cols;
			if (!isFirst && idx == 0)
				break;
			isFirst = 0;
			while(col >= lens[idx]){
				if (lens[idx] > cols)
					return 0;
				col = col - lens[idx];
				if (col>0)
					col--;
				idx++;
				if (idx == lens.size()){
					ans++;
					idx = 0;
				}
			}
		}
		if (row < rows){
			int times = rows / row;
			ans = ans * times;
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<string> da;
	da.push_back("I");
	da.push_back("had");
	da.push_back("apple");
	da.push_back("pies");

	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.wordsTyping(da, 12, 5);
	
	vector<string> db;
	db.push_back("a");
	db.push_back("bcd");
	db.push_back("e");
//	ret = sol.wordsTyping(db, 3, 6);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
