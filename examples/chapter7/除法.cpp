#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;


int n;
int b;
int kcase=0;


bool is_illegal(int num1,int num2){
	int n1[5];
	int n2[5];
	
	if(num1>98765) return true;
	
	for(int i=0;i<5;i++){
		n1[i]=num1%10;
		num1/=10;
		
		n2[i]=num2%10;
		num2/=10;
		
		if(n1[i]==n2[i]) return true;
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(n1[i]==n2[j]) return true;
			else if(i!=j&&n1[i]==n1[j]) return true;
			else if(i!=j&&n2[i]==n2[j]) return true;
		}
	}
	
	return false;
	
}
int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(cin>>n&&n){
		bool flag=true;
		
		if(kcase++) printf("\n");
		
		for(int i=1234;i<=98765;i++){
			b=i*n;
			if(!is_illegal(b,i)){
				printf("%5d / %05d = %d\n",b,i,n);
				flag=false;
			}
		}
		
		if(flag){
			printf("There are no solutions for %d.\n",n);
		}
	}
	
	//fclose(stdin);
	//fclose(stdout);
} 
