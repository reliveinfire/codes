#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <list>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class LRUCache {
	public:
		LRUCache(int capacity) {
			cap = capacity;
			isFull = false;
			count = 0;
		}

		int get(int key) {
			if (table.find(key)!= table.end()){
				int ret = table[key];
				keylist.erase(keypos[key]);
				keylist.push_back(key);
				keypos[key] = --keylist.end();
				return ret;
			} else {
				return -1;
			}
		}

		void put(int key, int value) {
			if (table.find(key)!= table.end()){
				keylist.erase(keypos[key]);
				table.erase(key);
				keypos.erase(key);
			} else if (!isFull){
				count++;
				if (count == cap)
					isFull = true;
			} else {
				int oldkey = *(keylist.begin());
				keylist.erase(keylist.begin());
				table.erase(oldkey);
			}
			table[key] = value;
			keylist.push_back(key);
			keypos[key] = --keylist.end();

		}

		void show(){
			cout <<"+++++++++++\n";
			for (list<int>::iterator iter = keylist.begin() ; iter != keylist.end() ; iter++){
				cout << " " << *iter;
			}
			cout << endl;
			for (map<int,list<int>::iterator>::iterator iter = keypos.begin() ;
						iter != keypos.end() ; iter++){
				cout << " " << iter->first << ":" << &*(iter->second);
			}
			cout << endl;
			cout <<"------------\n";
		}
	private:
		int cap;
		int count;
		bool isFull;
		map<int,int> table;
		list<int> keylist;
		map<int, list<int>::iterator> keypos;
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
	LRUCache lru(2);
	lru.put(2,1);
	lru.show();
	lru.put(2,2);
	lru.show();
	cout << lru.get(2) << endl;
	lru.show();
	lru.put(1,1);
	lru.show();
	lru.put(4,1);
	lru.show();
	cout << lru.get(2) << endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
