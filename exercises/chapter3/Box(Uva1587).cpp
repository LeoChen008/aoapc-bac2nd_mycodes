#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Pallet{
	int w=0;
	int h=0;
}a[6];
bool compare(Pallet p1,Pallet p2){
	return p1.w==p2.w?p1.h>p2.h:p1.w>p2.w; 
}
int main(){
	while(cin>>a[0].w>>a[0].h){
		for(int i=1;i<6;i++){
			cin>>a[i].w>>a[i].h;
		}
		for(int i=0;i<6;i++){
			if(a[i].w<a[i].h){
				swap(a[i].w,a[i].h); 
			}
		}
		sort(a,a+6,compare);
		
		bool flag=true;
		if(a[0].w==a[1].w&&a[1].w==a[2].w&&a[2].w==a[3].w){
			flag=true;
			if(a[0].h==a[1].h&&a[1].h==a[4].w&&a[4].w==a[5].w){
				flag=true;
				if(a[2].h==a[3].h&&a[3].h==a[4].h&&a[4].h==a[5].h){
					flag=true;
				}
				else{
					flag=false;
				} 
			}
			else{
				flag=false;
			}
		}
		else{
			flag=false;
		}
		if(flag){
			cout<<"POSSIBLE"<<endl; 
		}
		else{
			cout<<"IMPOSSIBLE"<<endl;
		}
	}
} 
