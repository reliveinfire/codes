#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
struct INTERVAL{
	int start;
	int end;
	bool valid(){
		return start <= end;
	}
	bool operator<(const INTERVAL& that) const{
		return start < that.start;
	}
};
class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
    	INTERVAL inst;
	inst.start = start;
	inst.end = end-1;
	auto iter = upper_bound(all.begin(), all.end(), inst);
	if (iter!=all.begin()){
		if (isoverlap(inst, *prev(iter)))
			return false;
	}
	if (iter!=all.end()){
		if (isoverlap(inst, *iter))
			return false;
	}
	all.insert(inst);
	return true;
    }
private:
	set<INTERVAL> all;
	bool isoverlap(INTERVAL a, INTERVAL b){
		INTERVAL overlap;
		overlap.start = max(a.start, b.start);
		overlap.end   = min(a.end, b.end);
		return overlap.valid();
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
