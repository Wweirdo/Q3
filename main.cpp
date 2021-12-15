//week1判断这一年的1.1星期，week2判断这一年的某月1日星期
//day为某月的第几天，days为一年的第几天
#include <iostream>
using namespace std;
int main()
{
    int a,b,c,y1,y2;
    cin>>a>>b>>c>>y1>>y2;
    while(y1<=y2){
        int leapyear;
        int i=0;
        int month=0,week1=0,week2=0,day=0,days=0;
        int year=1850;
        int months[2][13]{{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
        for(;year<=y1;year++){
            if (year%4==0&&year%100!=0||year%400==0)
                i++;
        }
        if(y1%4==0&&y1%100!=0||y1%400==0){
            leapyear=1;
            week1=((y1-1850+i+1)%7);
            if(week1==0){
                week1=7;
            }
        }
        else{
            leapyear=0;
            week1=((y1-1850+i+2)%7);
            if(week1==0){
                week1=7;
            }
        }
        for(month=0;month<a;month++){
            days=days+months[leapyear][month];
        }
        week2=(week1+days%7)%7;
        if(week2==0){
            week2=7;
        }
        day=(b-1)*7+c-week2+1;
        if(day<=months[leapyear][a])
            cout<<"  "<<y1<<"//"<<a<<"//"<<day<<endl;
        else{
            cout<<"none"<<endl;
        }
        y1++;
    }
}
