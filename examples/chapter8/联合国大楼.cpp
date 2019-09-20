#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int n; 
int main(void){
	while(cin>>n){
		printf("%d %d %d\n",2,n,n);
		for(int w=0;w<n;w++){
			for(int l=0;l<n;l++){
				printf("%c",w<26?w+'A':w-26+'a');
			}
			printf("\n");
		}
		cout<<endl;
		for(int w=0;w<n;w++){
			for(int l=0;l<n;l++){
				printf("%c",l<26?l+'A':l-26+'a');
			}
			printf("\n");
		}
	}
} 
