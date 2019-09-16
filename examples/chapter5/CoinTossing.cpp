#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void coin_tossing(){
	int n,head_num=0;
	double ratio;
	while(true){
		head_num=0;
	    srand((unsigned)time(NULL));
	    cout<<"Please input the number:"<<endl;
	    cin>>n;
	    for(int i=0;i<n;i++){
		    int coin=rand()%2;
		    if(coin==1) head_num++;
	    }
	    ratio=(double)head_num/(double)n;
	    cout<<ratio<<endl;
    }
} 
void three_dice(){
	int nine_num=0,ten_num=0;
	int sum,n;
	double ratio_nine;
	double ratio_ten;
	cout<<"Please input the number of running this programe:"<<endl;
	cin>>n;
	
	srand((unsigned)time(NULL));
	
	for(int i=0;i<n;i++){
		int first_dice=(rand()%7)+1;
		int second_dice=(rand()%7)+1;
		int third_dice=(rand()%7)+1;
		
		sum=first_dice+second_dice+third_dice;
		
		if(sum==9) nine_num++;
		else if(sum==10) ten_num++;
	}
	
	ratio_nine=(double)nine_num/(double)n;
	ratio_ten=(double)ten_num/(double)n;
	cout<<ratio_nine<<"  "<<ratio_ten<<endl;
	
}
int main(void){
	//coin_tossing();
	while(true) three_dice();
}
