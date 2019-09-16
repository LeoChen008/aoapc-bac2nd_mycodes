#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 25
using namespace std;
int k,m,n;
bool people[maxn];
int go(int p,int d,int t){
	while(t--){
		do{
			p=(p+d+n-1)%n+1;
		}while(!people[p]);
	}
	return p;
}
int main(){
	while(scanf("%d%d%d",&n,&k,&m)==3&&n){
		for(int i=1;i<=n;i++)people[i]=true;
		int left=n;
		int A=n,B=1;
		while(left){
			A=go(A,1,k);
			B=go(B,-1,m);
			printf("%3d",A);
			left--;
			if(A!=B){
				printf("%3d",B);
				left--;
			}
			people[A]=false;
			people[B]=false;
			if(left)cout<<","; 
		}
		cout<<endl;
	}
}
