#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
	root = new TrieNode();
    }
    void insert(string key, int val) {
    	int update;
    	if (used.count(key)==0){
		used[key] = val;
		update = val;
	} else {
		int tmp = used[key];
		used[key] = val;
		update = val - tmp;
	}
	TrieNode* idx = root;
	cout << key << endl;
	for (int i = 0 ; i < key.size() ; i++){
		char cc = key[i];
		cout << cc << endl;
		if (idx->next[cc-'a']==NULL){
			idx->next[cc-'a'] = new TrieNode();
		}
		idx = idx->next[cc-'a'];
		idx->count += update;
	}
		idx->word = 1;
    }
    int sum(string prefix) {
	TrieNode* idx = root;
	for (int i = 0 ; i < prefix.size() ; i++){
		char cc = prefix[i];
		if (idx!=NULL){
			idx = idx->next[cc-'a'];
		} else {
			return 0;
		}
	}
	if (idx != NULL)
		return idx->count;
	else
		return 0;
    }
private:
	unordered_map<string,int> used;
	struct TrieNode{
		int word;
		int count;
		TrieNode* next[26];
		TrieNode(){word = 0; count = 0; 
		for (int i = 0 ; i < 26 ; i++)
			next[i] = NULL;
		}
	};
	TrieNode* root;
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	MapSum ms;
	ms.insert("apple",3);
	cout << ms.sum("ap") <<endl;
	ms.insert("app",2);
	return 0;
}
