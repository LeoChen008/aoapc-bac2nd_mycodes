/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

const int maxn=100000+5;

int n,L;
int sum[maxn],p[maxn];

inline
int compare_tan(int x1,int x2,int x3,int x4){
	return (sum[x2]-sum[x1-1])*(x4-x3+1)-(sum[x4]-sum[x3-1])*(x2-x1+1);
} 

int main(void){
	int T;
	int ansl,ansr;
	string str;
	cin>>T;
	while(T--){
		cin>>n>>L;
		cin>>str;
		
		sum[0]=0;
		for(int i=1;i<=n;++i)sum[i]=sum[i-1]+str[i-1]-'0';
		
		ansl=1;ansr=L;
		int i=0,j=0,res;
		for(int r=L;r<=n;++r){
			while(j-i>1 && compare_tan(p[j-2],r-L,p[j-1],r-L) >= 0) j--;
			p[j++]=r-L+1;
			
			while(j-i>1 && compare_tan(p[i],r,p[i+1],r) <= 0) i++;
			
			res=compare_tan(p[i],r,ansl,ansr);
			if(res>0 || res==0 && r-p[i]<ansr-ansl){
				ansl=p[i];ansr=r;
			} 
		}
		
		printf("%d %d\n",ansl,ansr);
	}
	return 0;
}
