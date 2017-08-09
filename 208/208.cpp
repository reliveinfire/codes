#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
class mTreeNode{
	public:
		int leaf;
		mTreeNode* child[26];
		mTreeNode(){
			for (int i = 0 ; i < 26; i++){
				leaf = 0;
				child[i] = NULL;
			}
		}
};
class Trie {
	public:
		/** Initialize your data structure here. */
		Trie() {
			root = new mTreeNode();	
		}

		/** Inserts a word into the trie. */
		void insert(string word) {
			mTreeNode* idx = root;
			if (word.empty())
				return;
			for (int i = 0 ; i < word.size() ; i++){
				if (idx->child[word[i] - 'a'] ==NULL){
					idx->child[word[i] - 'a'] = new mTreeNode();
				}
				idx = idx->child[word[i]-'a'];
			}
			idx->leaf = 1;
		}

		/** Returns if the word is in the trie. */
		bool search(string word) {
			mTreeNode* idx = root;
			if (word.empty())
				return true;
			for (int i = 0 ; i < word.size() ; i++){
				if (idx->child[word[i] - 'a'] ==NULL){
					return false;
				}
				idx = idx->child[word[i]-'a'];
			}
			if (idx->leaf)
				return true;
			else
				return false;
		}

		/** Returns if there is any word in the trie that starts with the given prefix. */
		bool startsWith(string prefix) {
			mTreeNode* idx = root;
			for (int i = 0 ; i < prefix.size() ; i++){
				if (idx->child[prefix[i] - 'a'] ==NULL){
					return false;
				}
				idx = idx->child[prefix[i]-'a'];
			}
			return true;
		}
	private:
		mTreeNode* root;
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	int ret;
	Trie tr;
	tr.insert("abcd");
	tr.insert("defrg");
	cout << tr.search("aa") << endl;
	cout << tr.search("defrg") << endl;
	cout << tr.startsWith("dada") << endl;
	cout << tr.startsWith("def") << endl;
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
