#include <iostream>

using namespace std;
int month[20];
int main()
{
    int day=0,week;
    int a, b, c, y[3];
    cin>>a>>b>>c>>y[0]>>y[1];
    if(y[0]>y[1])swap(y[0],y[1]);
    for(int i=y[0]; i<=y[1]; i++)
    {
        // 首先判断是否是闰年 确定每月的天数
        if(i%400==0||i%4==0&&i%100!=0)
        {
            month[0]=31;
            month[1]=29;
            month[2]=31;
            month[3]=30;
            month[4]=31;
            month[5]=30;
            month[6]=31;
            month[7]=31;
            month[8]=30;
            month[9]=31;
            month[10]=30;
            month[11]=31;
        }
        else
        {
            month[0]=31;
            month[1]=28;
            month[2]=31;
            month[3]=30;
            month[4]=31;
            month[5]=30;
            month[6]=31;
            month[7]=31;
            month[8]=30;
            month[9]=31;
            month[10]=30;
            month[11]=31;
        }
        // 然后用当前年份 - 1850 得到之间有几年 并得到中间的天数
        day=i-1850;

        day*=365;

        // 补上中间是闰年多出的一天
        for(int j=1850; j<i; j++)
        {
            if(j%400==0||j%4==0&&j%100!=0)
            {
                day++;
            }
        }

        // 从当前年开始算 
        int date=0;
        // 一直加到当前月 得到前几个月一共有多少天
        for(int j=0; j<a-1; j++)
        {

            day+=month[j];

        }

        // 从当前月开始算
        // 因为是第b个星期几 所以前b-1个星期是一定有的
        if(b>1)
        {
            // 一直加到当前星期的前一个星期 得到当前月份在该星期第一天的天数
            date=(b-1)*7;
        }
        //月开始时候的星期 就是data现在对应的星期
        week=(day%7+1)%7+1; //因为1850.1.1 是星期一
        
        // 不是星期c
        while(week!=c)
        {
            // 天数往后推一天
            date++;
            // 星期数往后推一天
            week++;
            // 当week > 7的时候 -=7
            if(week>7)week-=7;
        }
        // 因为date一开始等于前b-1个星期的最后一天 而week是第一个星期的第一天往后加 所以date要多加一天
        date++;

        if(date>month[a-1]) {cout<<"none"<<endl;}
        else
        {
            if(a>=10){
                if(date>=10)
                    cout <<i<<"/"<< a<<"/"<< date << endl;
                else
                    cout <<i<<"/"<< a<<"/0"<< date << endl;
            }
            if(a<10){
                if(date>=10)
                    cout <<i<<"/0"<< a<<"/"<< date << endl;
                else
                    cout <<i<<"/0"<< a<<"/0"<< date << endl;
            }
        }
    }

    return 0;
}

