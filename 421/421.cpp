#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
class TrieNode
{
	public:
		TrieNode* next[2];
		TrieNode(){
			next[0] = NULL;
			next[1] = NULL;
		}
};

class Solution {
	public:
	int result;
	int findMaximumXOR(vector<int>& nums){
		int result = -1;
		if (nums.empty())
			return 0;

		TrieNode* root = new TrieNode();

		for (int i = 0 ; i < nums.size() ; i++){
			buildTree(root, nums[i]);
		}

		for (int i = 0 ; i < nums.size() ; i++){
			TrieNode* curr = root;
			int index;
			int tmp = 0;
			for (int j = 31 ; j >= 0 ; j--){
				index = (nums[i] >> j) & 0x1 ? 0 : 1; // 不同方向
				if (curr->next[index]){
					tmp = tmp + (0x1 << j);
					curr = curr->next[index];
				} else {
					curr = curr->next[index^1];
				}
//				cout << nums[i] << ":"<<j << ":" << tmp<<endl;
			}
			result = max(tmp, result);
		}
		return result;
	}

	void buildTree(TrieNode* root, int value){
		int index;
		TrieNode* curr = root;
		for (int i = 31 ; i >= 0 ; i--){
			index = (value >> i) & 0x1;
//			cout << " " << index;
			if (curr->next[index] == NULL){
				TrieNode* next = new TrieNode();
				curr->next[index] = next;
			}
			curr = curr->next[index];
		}
//		cout << endl;
		return;
	}

};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	int A[] = {3,10,5,25,2,8};
	genVector(da, A);
	Solution sol;
	ret = sol.findMaximumXOR(da);
	cout << ret << endl;

	return 0;
}
