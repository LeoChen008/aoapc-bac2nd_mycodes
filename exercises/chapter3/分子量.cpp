#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 85
using namespace std;
const char* a="CHON";
const double b[]={12.01,1.008,16.00,14.01};
int main(){
	int T;
	cin>>T;
	char s[maxn];
	while(T--){
		scanf("%s",s);
		double sum=0.0;
		int len=strlen(s);
		for(int i=0;i<len;i++){
			double f=0.0;
			int num=1;
			for(int j=0;j<4;j++){
				if(s[i]==a[j]){
					f=b[j];
				}
			}
			if(f==0.0) continue;
			if(i+1<len&&s[i+1]-'0'<=9){
				int tens=s[i+1]-'0';
				if(i+2<len&&s[i+2]-'0'<=9)
				    num=tens*10+s[i+2]-'0';
				else
				    num=tens;
			}
			sum+=f*num;
		}
		printf("%.3f\n",sum);
	}
}
