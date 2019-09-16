#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n>=1&&n<=20){
		int blank=0;
		for(int i=n;i>=1;i--){
			int num=blank/2;
			for(int j=1;j<=2*n-1;j++){
				if(num&&(num>=j||j>2*n-1-num)) cout<<' ';
				else cout<<'#';
			}
			cout<<endl; 
			blank+=2;
		}
	}
}
