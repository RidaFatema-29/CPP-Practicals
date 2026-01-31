//Practical no. 13
#include<iostream>
#include<climits>
using namespace std;

int temp[50], humd[50], poll[50];
int n, avgt=0, avgh=0, avgp=0;
int max_temp = 0, max_humd = 0, max_poll = 0;
int min_temp= INT_MAX, min_humd = INT_MAX, min_poll =INT_MAX;

void input(){
    cout<<"Enter total no. of entries : ";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Enter "<<i+1<<" Temperature : ";
        cin>>temp[i];
        cout<<"Enter "<<i+1<<" Humidity : ";
        cin>>humd[i];
        cout<<"Enter "<<i+1<<" Pollution Level : ";
        cin>>poll[i];
    }
}

void output(){
    cout<<"\n\n";
    cout<<" DATA ENTRIES "<<endl;
    cout<<"Sr.no \t Temperature \t Humidity \t Pollution Level "<<endl;
    for(int i=0; i<n; i++){
        cout<<i+1<<" \t"<<temp[i]<<" \t\t"<<humd[i]<<" \t\t"<<poll[i]<<endl;
    }
}

void average(){
    cout<<"\n\n";
    for(int i=0; i<n; i++){
        avgt += temp[i];
        avgh +=humd[i];
        avgp +=poll[i];
    }
    cout<<"Avg Temperature : "<<float(avgt/n);
    cout<<"\nAvg Humidity : "<<float(avgh/n);
    cout<<"\nAvg Pollution Lavel : "<<float(avgp/n);
}

void minmax(){
    cout<<"\n\n";
    for(int i=0; i<n; i++){
        max_temp = max(max_temp,temp[i]);
        min_temp = min(min_temp, temp[i]);

        max_humd = max(max_humd, humd[i]);
        min_humd = min(min_humd, humd[i]);

        max_poll = max(max_poll, poll[i]);
        min_poll = min(min_poll, poll[i]);
    }
    cout<<"Max Temperature : "<<max_temp;
    cout<<"\tMin Temperature : "<<min_temp;
    cout<<"\nMax Humidity : "<<max_humd;
    cout<<"\tMin Humidity : "<<min_humd;
    cout<<"\nMax Pollution Level : "<<max_poll;
    cout<<"\tMin Pollution Level : "<<min_poll;
}

void highlow(){
    cout<<"\n";
    if(max_temp>45){
        cout<<"\nTemp is not safe";
    }
    else{
        cout<<"\nTemp is normal";
    }
    if(max_humd>40){
        cout<<"\nHigh Humidity ";
    }
    else{
        cout<<"\nNormal Humidity";
    }
    if(max_poll>300){
        cout<<"\nHigh Pollution Rate";
    }
    else{
        cout<<"\nNormal Pollution Rate";
    }
}

void analysis(){
    cout<<"\n";
    if(max_temp>40 && max_humd>35){
        cout<<"\nHigh temp and humidity may cause health issues";
    }
    if(max_poll>250){
        cout<<"\nPollution Rate is increasing ";
    }

}

int main(){
input();
output();
average();
minmax();
highlow();
analysis();
}