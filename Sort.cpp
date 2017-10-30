#include "Sort.h"


void sortArrayLong(long int * array,const int arraySize);
void sortArrayInt( int * array,const int arraySize);
void sortArrayDouble(double * array,const int arraySize);
void sortArrayFloat(float * array,const int arraySize);

template <typename T>
inline void replaceInArray(long int * array,const int index0,const int index1);

template <typename T>
inline void replaceInArray(T * array,const int index0,const int index1){
	T v = array[index0];
	array[index0] = array[index1];
	array[index1] = v;
}

void sortArrayLong(long * array,const int arraySize){
	for(int i = 0;i<arraySize;i++){
		int indexOfBiggestValue = i;
		for(int j = i;j<arraySize;j++){
			if(array[j]>array[indexOfBiggestValue]){
				indexOfBiggestValue = j;
			}
		}
		replaceInArray(array,i,indexOfBiggestValue);
	}
}

void sortArrayInt( int * array,const int arraySize){
	for(int i = 0;i<arraySize;i++){
		int indexOfBiggestValue = i;
		for(int j = i;j<arraySize;j++){
			if(array[j]>array[indexOfBiggestValue]){
				indexOfBiggestValue = j;
			}
		}
		replaceInArray(array,i,indexOfBiggestValue);
	}
}

void sortArrayDouble(double * array,const int arraySize){
	for(int i = 0;i<arraySize;i++){
		int indexOfBiggestValue = i;
		for(int j = i;j<arraySize;j++){
			if(array[j]>array[indexOfBiggestValue]){
				indexOfBiggestValue = j;
			}
		}
		replaceInArray(array,i,indexOfBiggestValue);
	}
}

void sortArrayFloat(float * array,const int arraySize){
	for(int i = 0;i<arraySize;i++){
		int indexOfBiggestValue = i;
		for(int j = i;j<arraySize;j++){
			if(array[j]>array[indexOfBiggestValue]){
				indexOfBiggestValue = j;
			}
		}
		replaceInArray(array,i,indexOfBiggestValue);
	}
}