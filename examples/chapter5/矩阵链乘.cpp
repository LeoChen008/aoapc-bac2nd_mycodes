#include<iostream>
#include<cstdio>
#include<stack>
#include<string>

using namespace std;

const int maxn=26;

struct matrix{
	int m,n;
	matrix(int x=0,int y=0): m(x),n(y){}
}mar[maxn];

int main(void){
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++ ){
		string name;
		cin>>name;
		int k=name[0]-'A';
		cin>>mar[k].m>>mar[k].n;
	}
		
	stack<matrix> s;
		
	string exper;
	while(cin>>exper){
		int len=exper.length();
		int ans=0;
		bool flag=true;
		for(int i=0;i<len;i++){
			if(exper[i]-'A'>=0&&exper[i]-'A'<26){
				int j=exper[i]-'A';
				s.push(mar[j]);
			}
			else if(exper[i]==')'){
				matrix a=s.top();s.pop();
				matrix b=s.top();s.pop();
				if(a.n!=b.m){
					flag=false;
					break;
				}
				ans+=a.m*a.n*b.n;
				s.push(matrix(a.m,b.n));
			}
		}
		if(!flag){
			printf("error\n");
		}
		else{
			printf("%d\n",ans);
		}
	} 
}
