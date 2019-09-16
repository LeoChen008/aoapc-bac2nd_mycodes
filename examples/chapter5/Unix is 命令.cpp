#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

const int maxcol=60;
const int maxn=100+10;
string filenames[maxn];
void print(const string &s,int len,char extra){
	cout<<s;
	for(int i=0;i<len-s.length();i++){
		cout<<extra;
	} 
}
int main(void){
	int n;
	while(cin>>n){
		int Max=0;
		for(int i=0;i<n;i++){
			cin>>filenames[i];
			Max=max(Max,(int)filenames[i].length());
		}
		int cols=(maxcol-Max)/(Max+2)+1;
		int rows=(n-1)/cols+1;
		print("",60,'-');
		cout<<endl;
		sort(filenames,filenames+n);
		for(int r=0;r<rows;r++){
			for(int c=0;c<cols;c++){
				int index=c*rows+r;
				if(index<n){
					print(filenames[index],c==cols-1?Max:Max+2,' ');
				}
			
			}
				cout<<endl;
		}
	}
} 
