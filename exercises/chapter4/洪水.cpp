/*
* Created by LeoChen008
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;

const int maxn=30*30+5; 

int elevs[maxn];
int m,n,len;
double cubic;

inline
int judge(const int index){
	
	double sum=0.0;
	int level=elevs[index];
	
	for(int i=0;i<index;++i){
		sum+=level-elevs[i];
	}
	
	if(sum>cubic) return 1;
	else if(sum<cubic) return -1;
	
	return 0;
}
int main(void){
	int kcase=0;
	int low,high,mid;
	int res;
	bool flag;
	double ans_level,sum;
	while(cin>>m>>n&&m){
		len=m*n;
		for(int i=0;i<len;++i){
			cin>>elevs[i];
		}
		cin>>cubic;
		cubic/=100;
		sort(elevs,elevs+len);
		
		low=0;
		high=len-1;
		flag=false;
		while(low<=high){
			mid=low+(high-low)/2;
			
			res=judge(mid);
			if(res == 0) {
				flag=true;
				break;
			}
			else if(res > 0) high=mid-1;
			else low=mid+1;
		}
		
		printf("Region %d\n",++kcase);
		
		if(!flag){
			sum=cubic;
			for(int i=0;i<=high;++i) sum+=elevs[i];
			ans_level=sum/(high+1);
		}
		else      ans_level=elevs[mid];
		
		printf("Water level is %.2f meters.\n",ans_level);
		printf("%.2f percent of the region is under water.\n\n",low==high?
																(double)(mid+1)/len*100
																:(double)(high+1)/len*100);	
	}	
	return 0;
}
