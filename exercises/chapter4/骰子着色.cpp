#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

const int v[6][6]={{0,1,2,3,4,5},{1,5,2,3,0,4},
				   {2,1,5,0,4,3},{3,1,0,5,4,2},
				   {4,0,2,3,5,1},{5,4,2,3,1,0}};
char first[7];
char second[7];

inline bool check(const char *s){
	for(int i=0;i<6;i++){
		if(s[i]!=second[i]){
			return false;
		}
	}
	
	return true;
}
bool solve(){
	if(check(first)) return true;
	
	char temp[7];
	
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++) temp[j]=first[v[i][j]];
		if(check(temp)) return true; 
		for(int times=0;times<3;times++){
			ch=temp[1];
			temp[1]=temp[2];
			temp[2]=temp[4];
			temp[4]=temp[3];
			temp[3]=ch; 
			if(check(temp)) return true;
		} 
	}
	return false;
} 

int main(void){

	string str;
	while(cin>>str){
		for(int i=0;i<6;i++){
			first[i]=str[i];
			second[i]=str[6+i];
		}
		if(solve()){
			printf("TRUE\n");
		}else{
			printf("FALSE\n");
		}
	}
} 
