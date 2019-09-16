#include<iostream>
using namespace std;
int main(){
	int b1,b2,b3;
	int m1=3,m2=5,m3=7;
	int M1=m2*m3,M2=m1*m3,M3=m1*m2;
	int m=m1*m2*m3;
	while(cin>>b1>>b2>>b3){
		int M_1=0,M_2=0,M_3=0;
		for(int i=1;;i++){
			if(!M_1&&M1*i%m1==1)M_1=i;
			if(!M_2&&M2*i%m2==1)M_2=i;
			if(!M_3&&M3*i%m3==1)M_3=i;
			if(M_1&&M_2&&M_3)break;
		}
		int x=(b1*M1*M_1+b2*M2*M_2+b3*M3*M_3)%m;
		cout<<x<<endl;
	} 
}
