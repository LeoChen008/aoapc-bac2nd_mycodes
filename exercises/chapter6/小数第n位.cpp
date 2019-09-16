#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

long long a;
long long b;
long long n;
int main(void){
	long long sa,sn;
	while(cin>>a>>b>>n){
		sa=a%b;
		sn=n;
		
		while(sn-10>0){
			sa*=1e10;
			sa%=b;
			sn-=10;
		}
		while(--sn){
			if(sa==0){
				break;
			}
			else{
				sa*=10;
				sa=sa%b;
			}
		}
		
		if(sn==0&&sa==0){
			printf("000\n");
		}
		else{
			for(int i=0;i<3;i++){
				sa*=10;
				printf("%lld",sa/b);
				sa=sa%b;
			}
			printf("\n");
		}
	}
	
} 
