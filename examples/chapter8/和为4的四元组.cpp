#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=4000+5;
int A[maxn],B[maxn],C[maxn],D[maxn],sum[maxn*maxn];

int search_all(int pivot,int len){
	int left=pivot;
	int right=pivot+1;
	while(left>=0&&sum[left]==sum[pivot]) left--;
	while(right<len&&sum[right]==sum[pivot]) right++;
	return right-left-1;
} 

int main(void){
	int size;
	int T;
	int index,count,key,low,high,mid;
	cin>>T;
	while(T--){
		cin.get();cin.get(); 
				
		cin>>size;
		for(int i=0;i<size;i++) cin>>A[i]>>B[i]>>C[i]>>D[i];
		
		index=0;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				sum[index++]=A[i]+B[j];
			}
		}
		
		sort(sum,sum+index);
		
		count=0;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				key=-C[i]-D[j];
				low=0;high=index-1;
				while(low<=high){
					mid=low+(high-low)/2;
					if(key==sum[mid]){
						count+=search_all(mid,index);
						break;
					}
					else if(sum[mid]<key) low=mid+1;
					else    high=mid-1;
				}			
			}
		} 
		
		printf("%d\n",count);
		
		if(T) printf("\n");
	}	
} 
