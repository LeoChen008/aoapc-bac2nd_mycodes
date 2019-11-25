/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstdio>
using namespace std;

const int maxm = 200000+5;

int n,m;
struct Gate{
	int a,b;
	int out;
}gates[maxm];

int output(int in) { //input 1111....000, 'in' for number of 1 
	int in1,in2;
	int v1,v2;
	for(int i=1; i<=m; ++i){
		in1 = gates[i].a;
		in2 = gates[i].b;
		
		if(in1 < 0) v1 = -in1 <= in;
		else v1 = gates[in1].out;
		
		if(in2 < 0) v2 = -in2 <= in;
		else v2 = gates[in2].out;
		
		gates[i].out = !(v1&&v2);
	}
	
	return gates[m].out;
}

inline
int search_x(int out0) {
	int low=1, high=n;
	int mid;
	while(low < high){
		mid = low + (high-low)/2;
		if(output(mid) == out0) low = mid+1;
		else high = mid; 
	} 
	
	return low;
}
int main(void){
	int D;
	cin >> D;
	while(D--) {
		cin >> n >> m;
		for(int i=1; i<=m; ++i) cin >> gates[i].a >> gates[i].b;
		
		int out0 = output(0); // all 0
		int outn = output(n); // all 1
		
		if(out0 == outn )
			for(int i=0; i<n; ++i) printf("0");
		else
		{
			int x=search_x(out0);
			
			for(int i=1; i<x; ++i) printf("1");
			printf("x");
			for(int i=x+1; i<=n; ++i) printf("0");
		}
		printf("\n");  
	}
	return 0;
} 
