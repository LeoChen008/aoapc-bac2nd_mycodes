#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 3050
int num[maxn];
int s[maxn];  //存储被除数	 
int u[maxn]; //存储 循环小数的长度 
using namespace std;
int main(){
	int a,b;
	while(scanf("%d%*c%d",&a,&b)!=EOF){
		memset(num,0,sizeof(num));
		memset(u,0,sizeof(u));
		memset(s,0,sizeof(s));
		int count=0;
		int n=a;
		num[count++]=n/b;
		n=n%b;
		while(!u[n]&&n){
			u[n]=count;
			s[count]=n;
			num[count++]=n*10/b;
			n=n*10%b; 
		}
		printf("%d/%d = %d",a,b,num[0]);
		printf(".");
		for(int i=1;i<count&&i<=50;i++){
			if(n&&s[i]==n)printf("(");
			printf("%d",num[i]);
		}
		if(!n)printf("(0");
		if(count>50)printf("..."); 
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n",!n?1:count-u[n]);	
	}
}
