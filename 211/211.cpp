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

class WordDictionary {
	public:
		/** Initialize your data structure here. */
		WordDictionary() {
			root = new mTreeNode();
		}

		/** Adds a word into the data structure. */
		void addWord(string word) {
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

		/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
		bool search(string word) {
			return tt(word, 0, root);
		}
	private:
		mTreeNode* root;
		bool tt(string word, int start, mTreeNode* node){
			bool ret;
			mTreeNode* idx = node;
			for (int i = start ; i < word.size() ; i++){
				if (word[i] == '.'){
					if (i == word.size() - 1 ){
						for (int j = 0 ; j < 26 ; j++){
							if (idx->child[j] != NULL && idx->child[j]->leaf)
								return true;
						}
						return false;
					} else {
						for (int j = 0 ; j < 26 ; j++){
							if (idx->child[j] != NULL)
								ret = tt(word, i + 1, idx->child[j]);
							if (ret)
								return true;
						}
						return false;
					}
				} else {
					if (idx->child[word[i] - 'a'])
						idx = idx->child[word[i] - 'a'];
					else
						return false;
				}
			}
			if (idx->leaf)
				return true;
			else
				return false;
		}
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
	WordDictionary wd;
	wd.addWord("bad");
	wd.addWord("dad");
	wd.addWord("mad");

	cout << wd.search("pad") << "\n";
	cout << wd.search("bad") << "\n";
	cout << wd.search(".ad") << "\n";
	cout << wd.search("b..") << "\n";
	cout << wd.search("...") << "\n";
	cout << wd.search("....") << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
