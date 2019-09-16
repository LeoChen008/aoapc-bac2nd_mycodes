#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn=18+2;

int n;
long long seq[maxn];
int kcase=0;
long long res;

int main(void){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>seq[i];
		}
		
		res=0;
		long long temp;
				
		for(int i=0;i<n;i++){
			temp=1;
			for(int j=i;j<n;j++){
				temp*=seq[j];
				
				res=max(res,temp);
			}
			
			
		}
		
		printf("Case #%d: The maximum product is %lld.\n\n",++kcase,res);
		
	} 
	//fclose(stdin);
	//fclose(stdout); 
} 
