#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxr=10+5;
const int maxb=30+5;
const int maxp=100+5;

int num_r;		//number of operating rooms 
int num_b;		//number of recovery beds 
int num_p;		//number of patient
int t_trans;  //time of transport patient from operating rooms to recovery beds 
int t_pr;		//time of perpare operating rooms for next patient
int t_pb;		//time of perpare recovery bed for next patient
char ch[5];

struct Time{
	int hour;
	int minute;
	Time(int hour=0,int minute=0):hour(hour),minute(minute){}
	
	int operator-(const Time &t) const{
		int minutes=(this->hour-t.hour)*60+this->minute-t.minute;
		return minutes;
	}
	
	Time operator+(const Time &t){
		Time temp;
		temp.minute+=this->minute+t.minute;
		temp.hour+=this->hour+t.hour+temp.minute/60;
		temp.minute%=60;
		return temp;
	}
}time_now,start_day;

struct Room{
	int use_t;
	int pid;
	bool available;
	Room(int use_t=0,bool available=true):use_t(use_t),available(available){}
}rooms[maxr];

struct Bed{
	int use_t;
	int pid;
	bool available;
	Bed(int use_t=0,bool available=true):use_t(use_t),available(available){}
}beds[maxb];

struct Patient{
	char name[8];
	bool avail;
	bool sur_finish;
	bool rec_finish;
	Time start_sur;
	Time end_sur;
	Time start_rec;
	Time end_rec; 
	int sur_t;
	int rec_t;
	int sur_id;
	int rec_id;
	Patient(bool sur=false,bool rec=false,bool avail=true):
	sur_finish(sur),rec_finish(rec),avail(avail){}
	
}patient[maxp];

bool all_finish(){
	bool flag=true;
	for(int i=0;i<num_p;i++){
		if(!patient[i].sur_finish||!patient[i].rec_finish){
			flag=false;
			break;
		}
	}
	
	return flag;
}
void solve(){
	while(!all_finish()){
		
		for(int i=0;i<num_p;i++){
			if(!patient[i].avail&&time_now-patient[i].start_sur==patient[i].sur_t){
				patient[i].end_sur=time_now;
				patient[i].avail=true;
				patient[i].sur_finish=true;
			}
			if(!patient[i].avail&&patient[i].sur_finish&&time_now-patient[i].start_rec==patient[i].rec_t){
				patient[i].end_rec=time_now;
				patient[i].rec_finish=true;
			}
		}
		
		
		for(int i=0;i<num_r;i++){
			if(!rooms[i].available&&time_now-patient[rooms[i].pid].end_sur==t_pr){
				rooms[i].available=true;
			}
			
			if(rooms[i].available){
				for(int j=0;j<num_p;j++){
					if(patient[j].avail&&!patient[j].sur_finish){
						rooms[i].available=false;
						rooms[i].pid=j;
						rooms[i].use_t+=patient[j].sur_t;
						patient[j].avail=false;
						patient[j].sur_id=i+1;
						patient[j].start_sur=time_now;
						break;
					}
				}
			}
		}
		
		
		for(int i=0;i<num_b;i++){
			if(!beds[i].available&&time_now-patient[beds[i].pid].end_rec==t_pb){
				beds[i].available=true;
			}
			if(beds[i].available){
				for(int j=0;j<num_p;j++){
					if(patient[j].avail&&patient[j].sur_finish&&!patient[j].rec_finish){
						beds[i].available=false;
						beds[i].pid=j;
						beds[i].use_t+=patient[j].rec_t;
						patient[j].avail=false;
						patient[j].rec_id=i+1;
						patient[j].start_rec=time_now+Time(0,t_trans);
						break;
					}
				}
			}
		}
		
		time_now.minute++;
		if(time_now.minute>=60){
			time_now.hour+=time_now.minute/60;
			time_now.minute%=60;
		}
	}
}
void time_format(Time temp){
	if(temp.hour>=10){
		ch[0]=temp.hour/10+'0';
	}else{
		ch[0]=' ';
	}
	
	ch[1]=temp.hour%10+'0';
	ch[2]=':';
	ch[3]=temp.minute/10+'0';
	ch[4]=temp.minute%10+'0';	
}
void print_table1(){
	cout<<" Patient          Operating Room          Recovery Room"<<endl;
	cout<<" #  Name     Room#  Begin   End      Bed#  Begin    End"<<endl; 
	cout<<" ------------------------------------------------------"<<endl; 
	for(int i=0;i<num_p;i++){
		printf("%2d  %-8s  %2d   ",i+1,patient[i].name,patient[i].sur_id);
		time_format(patient[i].start_sur);
		printf("%s   ",ch);
		time_format(patient[i].end_sur);
		printf("%s     %2d   ",ch,patient[i].rec_id);
		time_format(patient[i].start_rec);
		printf("%s   ",ch);
		time_format(patient[i].end_rec);
		printf("%s\n",ch);
	}
}
void print_table2(){
	cout<<"Facility Utilization"<<endl;
	cout<<"Type  # Minutes  % Used"<<endl;
	cout<<"-------------------------"<<endl;
	
	int sum=time_now-start_day;
	sum--;
	
	for(int i=0;i<num_r;i++){
		printf("Room %2d    %4d   %5.2f\n",i+1,rooms[i].use_t,(float)rooms[i].use_t/sum*100);
	} 
	
	for(int i=0;i<num_b;i++){
		printf("Bed  %2d    %4d   %5.2f\n",i+1,beds[i].use_t,(float)beds[i].use_t/sum*100);
	}
}

void init(){
	time_now.hour=0;
	time_now.minute=0;
	for(int i=0;i<num_r;i++){
		rooms[i].use_t=0;
		rooms[i].available=true;
	}
	
	for(int i=0;i<num_b;i++){
		beds[i].use_t=0;
		beds[i].available=true;
	}
}

int main(void){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	string hour;
	while(cin>>num_r>>num_b>>hour>>t_trans>>t_pr>>t_pb>>num_p){
		init();
		for(int i=0;i<hour.length();i++){
			int t=hour[i]-'0';
			time_now.hour+=t+t*(1-i)*10;
			start_day=time_now; 
		}
		
		
		for(int i=0;i<num_p;i++){
			scanf("%s",patient[i].name);
			cin>>patient[i].sur_t;
			cin>>patient[i].rec_t;
			patient[i].avail=true;
			patient[i].sur_finish=false;
			patient[i].rec_finish=false;
		}
		solve();
		
		print_table1();
		printf("\n");
		print_table2();
		printf("\n");
	}
	
	//fclose(stdin); 
	//fclose(stdout); 
} 
