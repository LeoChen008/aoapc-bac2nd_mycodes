#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

void fill_rand_num(vector<int> &v,int cnt){
	v.clear();
	for(int i=0;i<cnt;i++){
		v.push_back(rand());
	}
}
void sort_test(vector<int> &v){
	sort(v.begin(),v.end());
	for(int i=0;i<v.size()-1;i++){
		assert(v[i]<=v[i+1]);
	}
}
int main(void){
	vector<int> v;
	srand(time(NULL));
	fill_rand_num(v,1000);
	sort_test(v);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	
} 
