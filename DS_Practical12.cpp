#include<iostream>
using namespace std;

int n=5, temp;
int arr[10];

void bubble(){
    cout<<"\nBUBBLE SORT";
    for(int r=0; r<n-1; r++){
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            temp = arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    cout<<"\nAfter "<<r+1<<" pass : ";
    for(int i=0; i<n; i++){
        cout<<"\t"<<arr[i];
    }
    }
    cout<<"\nUsing Bubble Sort :-";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
}

void selection(){
    cout<<"\nSELECTION SORT ";
    // for(int pass=0; pass<n-1; pass++){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    
    }
    cout<<"\n Using Selection sort : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
}
    


void insertion(){
    // for(int r=0; r<n-1; r++){
        for(int i=1; i<n; i++){
            for(int j=0; j<i-1;j++){
                if(arr[i]<arr[j]){
                    temp= arr[i];
                    arr[i]= arr[j];
                    arr[j]=temp;
                }
            }
        }
        cout<<"\nAfter "<<" pass : ";
        for(int i=0; i<n; i++){
        cout<<"\t"<<arr[i];
    // }
}
cout<<"\n Using Insertion sort : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    cout<<"\nEnter Marks of 5 Subjects : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    bubble();
    selection();
    insertion();
}