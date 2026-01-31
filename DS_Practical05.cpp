#include<iostream>
using namespace std;

const int MAX = 10;
int n,m;
int coeff1[MAX], coeff2[MAX];

void read1(){
    cout<<"Enter the no. of terms for First Polynomial : ";
    cin>>n;
    coeff1[n];
    for(int i=0; i<n; i++){
        cout<<"Enter coefficient for "<<i<<" exponent : ";
        cin>>coeff1[i];
    }
}

void display1(){
    for(int i=n-1; i>=0; i--){
        cout<<coeff1[i]<<"x^"<<i;
        if(i!=0){
            cout<<" + ";
        }
    }

}

void read2(){
    cout<<"\n\nEnter the no. of terms for Second Polynomial : ";
    cin>>m;
    coeff2[m];
    for(int i=0; i<m; i++){
        cout<<"Enter coefficient for "<<i<<" exponent : ";
        cin>>coeff2[i];
    }
}

void display2(){
    for(int i=m-1; i>=0; i--){
        cout<<coeff2[i]<<"x^"<<i;
        if(i!=0){
            cout<<" + ";
        }
    }

}

void addition(){
    int maxDeg = (n>m)? n:m;
    int sum[maxDeg+1];

    for(int i=0; i<=maxDeg; i++){
        int a = (i<=n)? coeff1[i] : 0;
        int b = (i<=m)? coeff2[i] : 0;
        sum[i]= a+b;
    }

    cout<<"\n\n Addition of Two Polynomial : ";
    for(int i=maxDeg-1; i>=0; i--){
        cout<<sum[i]<<"x^"<<i;
        if(i!=0){
            cout<<" + ";
        }
    }
}

int main(){
    cout<<"\n Polynomials \n\n";
read1();
display1();
read2();
display2();
addition();
return 0;
}