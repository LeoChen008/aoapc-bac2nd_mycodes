/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstdio>

using namespace std;

typedef unsigned long long LLU;
const int maxs = 32;

int main(void){
	int n,sp,sq;
	int a,b,a1,b1;
	LLU k,Pof,Qof,temp;
	while (cin>>n>>sp>>sq) {
		k=0xffffffffffffffff;
		for(a=0;a<maxs;++a){
			for(b=0;b<maxs;++b){
				Pof=(n-1)*sp;
				Qof=(Pof+(Pof<<a))>>b;
				temp = Qof+sq;
				if (temp>=n*sq&&temp<k){
					k=temp;
					a1=a;
					b1=b;
				}
			}
		}
		
		printf("%llu %d %d\n",k,a1,b1);
	} 
	return 0; 
} 

