#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 105
using namespace std;
char a[maxn];
char b[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int cnt1[26],cnt2[26];
	while(cin>>a>>b){
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		int alen=strlen(a);
		int blen=strlen(b);
		for(int i=0;i<alen;i++){
			cnt1[a[i]-'A']+=1;
		}
		for(int j=0;j<blen;j++){
			cnt2[b[j]-'A']+=1;
		}
		sort(cnt1,cnt1+26,cmp);
		sort(cnt2,cnt2+26,cmp);
		bool flag=true;
		for(int i=0;i<26;i++){
			if(cnt1[i]!=cnt2[i])
			{
				cout<<"NO"<<endl;
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}
		
	}
}
