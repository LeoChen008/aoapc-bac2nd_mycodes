#include<iostream>
#include<cstdio>
using namespace std;
unsigned int reverse(unsigned int ip){
	unsigned int temp=~0;
	for(int i=31;i>=0;i--){
		if(ip&(1<<i)){
			if(i==31) temp=0;//incase left shift 32 bit
			else temp=temp<<(i+1);
			break;
		}
	}
	return temp;
}
int main(void){
	int m,i;
	unsigned int a,b,c,d;
	unsigned int ip,mask,low_ip,temp,temp2;
	while(cin>>m){
		ip=0;
		getchar();
		for(i=0;i<m;i++){
			scanf("%u.%u.%u.%u",&a,&b,&c,&d);
			getchar();
			if(i<2) {ip^=a<<24;ip^=b<<16;ip^=c<<8;ip^=d;}			
			if(!i)  temp=ip;
			
			if(i>=2){
				temp2=(a<<24)+(b<<16)+(c<<8)+d; 
				ip|=temp^temp2; 
			}
		}
		if(i==1) ip=0;
		mask=reverse(ip);
		low_ip=mask&temp;
		printf("%u.%u.%u.%u\n",low_ip>>24,(low_ip>>16)&255,
								(low_ip>>8)&255,low_ip&255);
		printf("%u.%u.%u.%u\n",mask>>24,(mask>>16)&255,
								(mask>>8)&255,mask&255);
	}
} 
