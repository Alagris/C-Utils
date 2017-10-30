#include "timer.h"
#include <iostream>
#include <vector>

using namespace std;
main(){
	start();
	vector<string> v;
	for(int i = 0;i<1000;i++){
		v.push_back("hello");
	}
	cout<<endTimeNano()<<endl;

	start();
	string s;
	for(int i = 0;i<1000;i++){
		s+="hello";
	}
	cout<<endTimeNano();
}