#include "fuzzy_compare.h"
#include <string>
#include <algorithm>    // min,max

using namespace std;

inline size_t min(const size_t a,const size_t b ){
	return a<b? a: b;
}
inline unsigned int max(const unsigned int a,const unsigned int b ){
	return a>b? a: b;
}
/**Returned value is always bigger or equal 0
* Very fuzzy,default method)could skip some letters in mainWord if distance is too far*/
unsigned int util_lib::fuzzyCompare(const string & w1, const string & w2){
	int output = 0;
	//scan w1 to find chars in w2
	//when w2.size() <= w1.size()
	//for every part in w1
	//try to find next char from w2
	//a - index of chars from w2 that is being searched for in current part
	//b - index of currently scanned char in w1
	//c - index of the last found char in w2
	//s - part start (inclduing)
	//e - part end (excluding)
	//iterating through parts
	const int searchRangeExcluding = 4;
	for(size_t s=0,e=searchRangeExcluding,c=0;c<w2.size() && s < e;c++){
		//iterating through chars in w2
		size_t b = 0;
		for(size_t a =c;a <w2.size();a++){
			//iterating through current part in w1
			b=s;
			for(;b<e;b++){
				if(w1[b] == w2[a]){
					output += int(searchRangeExcluding-(b-s));
					c = a;
					goto breakSecondLoop;
				}else if(tolower(w1[b]) == tolower(w2[a])){
					output += int(max(int(searchRangeExcluding-(b-s))-1,0));
					c = a;
					goto breakSecondLoop;
				}
			}
		}
		breakSecondLoop:
		s = b+1;
		e = min(s +searchRangeExcluding, w1.size() );

	}
	return (w1.size() == w2.size()) ? output:(output+1);
}

/**(not so fuzzy)doesn't skip any letters and only analyzes distance between them.Is faster than 1*/
unsigned int util_lib::fuzzyCompare2(const string & w1, const string & w2){
	int output=int(w1.size());//half of maximal similarity rate
	for(size_t i = 0,j=0,distance=0;i<w1.size();i++){
		if(w1[i]==w2[j]){
			output-= int(distance);
			j++;
			distance=0;
		}else if(tolower(w1[i])==tolower(w2[j])){
			output-= int(distance+1);
			j++;
			distance=0;
		}else{
			distance++;
		}
	}
	return  output<0?0: output;
}

/**(reverse,only a little bit more fuzzy than 2) skips maximally one letter.All input works as base of phrases that algorithm will try to find in mainWord.*/
unsigned int util_lib::fuzzyCompare3(const string & w1, const string & w2,long * startIncluding ,long *endIncluding ){
	float localSumMax = 0;
	for(size_t i = 0;i<w2.size();i++){
		for(size_t j =0;j<size_t(w1.size()*0.7);j++){

			if(tolower(w1[j])==tolower(w2[i])){
				float localSum = 0.5;
				long localStartIncluding=long(i);
				if(w1[j]==w2[i]){
					localSum+=0.5;
				}
				j++;
				size_t i2=i+1;
				for(bool letterInW1missing=0,letterInW2missing=0;i2<w2.size();i2++,j++){
					if(w1[j]==w2[i2]){
						if(letterInW1missing || letterInW2missing){
							letterInW1missing=0;
							letterInW2missing=0;
							localSum+=0.5;
						}else{
							localSum+=1;
						}
					}else if(tolower(w1[j])==tolower(w2[i2])){
						if(letterInW1missing|| letterInW2missing){
							letterInW1missing=0;
							letterInW2missing=0;
							localSum+=0.25;
						}else{
							localSum+=0.5;
						}
					}else{
						if(letterInW1missing){
							if(letterInW2missing){
								i2-=2;
								break;
							}else{
								letterInW2missing=1;
								j-=2;
							}
						}else{
							i2--;
							letterInW1missing=1;
						}
					}
				}

				if(localSum>localSumMax){
					localSumMax = localSum;
					if(startIncluding)*startIncluding = localStartIncluding;
					if(endIncluding)*endIncluding = i2;
				}
				break;
			}
		}
	}
	return int(localSumMax/float(w1.size())*float(w2.size()));
}
