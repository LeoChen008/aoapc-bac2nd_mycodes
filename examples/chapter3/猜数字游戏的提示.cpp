#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 1010
int a[maxn],b[maxn];
int main(){
	int n;
	int kcase=0;
	while(scanf("%d",&n)==1&&n){
		printf("Game %d:\n",++kcase);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(;;){
			int A=0,B=0;
			for(int i=0;i<n;i++){
				scanf("%d",&b[i]);
				if(a[i]==b[i]) {
					A++;
				}
			}
			if(b[0]==0) break;
			for(int num=1;num<=9;num++){
				int m1=0,m2=0;
				for(int i=0;i<n;i++){
					if(a[i]==num)m1++;
					if(b[i]==num)m2++;
				}
				if(m1<m2) B+=m1;
				else B+=m2;
			}
			printf("    (%d,%d)\n",A,B-A);
		}
	}
} 
