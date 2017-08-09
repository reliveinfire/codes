#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;
#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
	
    }

    void addNum(int num) {
    	int tmp;
	minheap.push(num);
	tmp = minheap.top();
	minheap.pop();
	maxheap.push(tmp);
	if (maxheap.size() > minheap.size()){
		tmp = maxheap.top();
		maxheap.pop();
		minheap.push(tmp);
	}
	return;	
    }

    double findMedian() {
    	if (minheap.empty() && maxheap.empty())
		return 0;
	if (minheap.size() > maxheap.size())
		return minheap.top();
	else {
		return (minheap.top() + maxheap.top()) / 2.0;
	}
    }
private:
	priority_queue<int, vector<int>, greater<int>> minheap;
	priority_queue<int, vector<int>, less<int>> maxheap;
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	MedianFinder mf;
	mf.addNum(1);
//	cout << mf.findMedian() << endl;
	mf.addNum(2);
	cout << mf.findMedian() << endl;
	mf.addNum(3);
	cout << mf.findMedian() << endl;

	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;


	return 0;
}
