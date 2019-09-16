#include<iostream>
#include<cstring>
#define maxn 10005
using namespace std;
int count[10];
int main(){
	int T;
	int num;
	cin>>T;
	while(T--){
		cin>>num;
		memset(count,0,sizeof(count));
		for(int n=1;n<=num;n++){
			int x=n;
			while(x>0){
				count[x%10]++;
				x/=10;
			}
		}
		for(int i=0;i<9;i++){
			printf("%d ",count[i]);
		}
		printf("%d",count[9]);
		cout<<endl;
	}
}
