#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,m;
	int kcase=0;
	while(cin>>n>>m&&n&&m){
		double sum=0.0;
		for(int i=n;i<=m;i++){
			sum+=(double)1/(i*i);
			if((int)sum*100000<1) {
				sum=0.00001;
				break;
			}
		}
		if(kcase) cout<<endl;
		printf("case %d: %.5f\n",++kcase,sum);
	}
}
