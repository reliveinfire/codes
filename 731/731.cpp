#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
struct Timestamp{
	int  time;
	char state;
	bool operator<(const Timestamp& that)const{
		if (time == that.time){
			// compare smaller 要小心!!!
			if (state=='s' && that.state=='e')
				return true;
			else
				return false;
		}
		return time < that.time;
	}
};
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
    	Timestamp s;
	Timestamp e;
	s.time = start;
	s.state = 's';
	e.time = end-1;
	e.state = 'e';
	times.insert(s);
	times.insert(e);
	if (pass())
		return true;
	cout << "false:" << start <<":" << end << endl;
	auto is = times.find(s);
	times.erase(is);
	auto ie = times.find(e);
	times.erase(ie);
	return false;
    }
private:
	multiset<Timestamp> times;
	bool pass(){
		int cnt = 0;
		auto iter = times.begin();
		while(iter!=times.end()){
			if (iter->state=='s')
				cnt++;
			else
				cnt--;
			if (cnt>2)
				return false;
			iter++;
		}
		return true;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	MyCalendarTwo mc;
	cout << mc.book(10,20) << endl;
	cout << mc.book(50,60) << endl;
	cout << mc.book(10,40) << endl;
	cout << mc.book( 5,15) << endl;
//	cout << mc.book( 5,10) << endl;
//	cout << mc.book(25,55) << endl;
	return 0;
}
