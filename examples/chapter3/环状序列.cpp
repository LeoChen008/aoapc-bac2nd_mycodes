#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 105
using namespace std;
bool isless(const char* ch,int m,int n,int len){
	for(int i=0;i<len;i++){
		if(ch[(m+i)%len]!=ch[(n+i)%len]){
			return ch[(m+i)%len]<ch[(n+i)%len];
		}
	}
	return false;
}
int main(){
	int T;
	char s[maxn];
	cin>>T;
	while(T--){
		scanf("%s",s);
		int index=0;
		int len=strlen(s);
		for(int i=1;i<len;i++){
			if(isless(s,i,index,len))index=i;
		}
		for(int i=0;i<len;i++)
		    cout<<s[(index+i)%len];
		cout<<endl;
	}
} 
