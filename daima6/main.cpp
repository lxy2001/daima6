#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#define n 28
using namespace std;
struct student{
    string num;
    string college;
    string name;
    int score[7]={0};
    double average_score;
};
struct judgment{
    string tname;
};
struct Max{
    int mlocation;
    int max;
};
struct Min{
    int nlocation;
    int min;
};
int main (){
    int y=0;
    student student[n];
    judgment judgment[7];
    Max max[n];
    Min min[n];
    ifstream outf("/Users/s20181106279/Desktop/tttt.txt");
    ifstream out("/Users/s20181106279/Desktop/ttt.txt");
    for(int i=0;i<n;i++){
        out>>student[i].num>>student[i].name>>student[i].college;
    }
    for(int i=1;i<=n+1;i++){
        if(i==1){
            for(int j=0;j<7;j++){
                outf>>judgment[j].tname;
            }
        }
        else{
            for(int k=0;k<7;k++){
                outf>>student[i-2].score[k];
            }
        }
    }
    for(int i=0;i<n;i++){
        max[i].max=student[i].score[0];
        max[i].mlocation=0;
        min[i].min=student[i].score[0];
        min[i].nlocation=0;
        for(int j=1;j<7;j++){
            if(max[i].max<student[i].score[j]){
                max[i].max=student[i].score[j];
                max[i].mlocation=j;
            }
            if(min[i].min>student[i].score[j]){
                min[i].min=student[i].score[j];
                min[i].nlocation=j;
            }
        }
    }
    for(int i=0;i<n;i++){
        double v=0;
        for(int k=0;k<7;k++){
            if(k!=max[i].mlocation&&k!=min[i].nlocation){
                v=v+student[i].score[k];
            }
        }
        student[y].average_score=v*1.0/5;
        y++;
    }
    string num1;
    string college1;
    string name1;
    int score1[8]={0};
    double average_score1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(student[j].average_score<student[j+1].average_score){
                average_score1=student[j].average_score;
                student[j].average_score=student[j+1].average_score;
                student[j+1].average_score=average_score1;
                num1=student[j].num;
                student[j].num=student[j+1].num;
                student[j+1].num=num1;
                college1=student[j].college;
                student[j].college=student[j+1].college;
                student[j+1].college=college1;
                name1=student[j].name;
                student[j].name=student[j+1].name;
                student[j+1].name=name1;
                for(int k=0;k<7;k++){
                    score1[k]=student[j].score[k];
                    student[j].score[k]=student[j+1].score[k];
                    student[j+1].score[k]=score1[k];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<7;j++){
            cout<<judgment[j].tname;
            cout<<" ";
            cout<<student[i].score[j];
            cout<<" ";
        }
        cout<<endl;
    }
    ofstream in("/Users/s20181106279/Desktop/ttttt.txt");
    if(in.is_open())
    {
        for(int i=0;i<n;i++){
            in<<left<<setw(10)<<student[i].num<<left<<setw(10)<<student[i].college<<left<<setw(10)<<student[i].name
            <<"排名:"<<left<<setw(10)<<i+1<<"平均分:"<<left<<setw(10)<<student[i].average_score;
            for(int j=0;j<7;j++){
                in<<judgment[j].tname;
                in<<" ";
                in<<student[i].score[j];
                in<<" ";
            }
            in<<endl;
        }
        in.close();
    }
    return 0;
    
}
