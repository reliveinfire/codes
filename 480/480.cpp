#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<double> medianSlidingWindow(vector<int>& nums, int k){
                multiset<int> minheap;
                multiset<int> maxheap;
                vector<double> res;
                int i=0, j=0;
                for (; i < nums.size() ; i++){
                        insertElement(minheap, maxheap, nums[i]);
                        if (i-j+1==k){
                                double median;
                                if (minheap.size() == maxheap.size()){
                                        double up = *minheap.begin();
                                        double down = *(--maxheap.end());
                                        //cout << "up down:" << up <<":" << down << endl;
                                        median = (up+down)/2.0;
                                } else {
                                        //cout << "up down:" << *minheap.begin() << endl;
                                        median = *minheap.begin();
                                }
                                res.push_back(median);
                                delElement(minheap, maxheap, nums[j]);
                                j++;
                        }
                }
                return res;
        }
        void insertElement(multiset<int>& minheap, multiset<int>& maxheap, int vv)
        {
                //cout << "insert:" << vv << endl;
		minheap.insert(vv);
		int min = *minheap.begin();
		minheap.erase(minheap.begin());
		maxheap.insert(min);
		if (maxheap.size() > minheap.size()){
			int max = *(--maxheap.end());
			maxheap.erase(--maxheap.end());
			minheap.insert(max);
		}
                return;
        }
        void delElement(multiset<int>& minheap, multiset<int>& maxheap, int vv){
                int min = *minheap.begin();
                if (vv >= min)
                        minheap.erase(minheap.find(vv));
                else
                        maxheap.erase(maxheap.find(vv));
                if (minheap.size() < maxheap.size()){
                        int max = *(--maxheap.end());
                        maxheap.erase(--maxheap.end());
                        minheap.insert(max);
                } else if (minheap.size() - maxheap.size() >= 2){
                        min = *minheap.begin();
                        minheap.erase(minheap.begin());
                        maxheap.insert(min);
                }
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//vector<int> A = {1,3,-1,-3,5,3,6,7};
	vector<int> A = {1,7,1,8,7,8};
	//vector<int> A = {1,4,2,3};
	Solution sol;
	int ret;
#if 1
	auto ret_vec = sol.medianSlidingWindow(A, 4);
	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
#endif
	cout <<endl;

	return 0;
}
