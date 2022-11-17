#include<iostream>
using namespace std;

bool transmit(int arr[] , int size)
{   
    string s="";
    for (int i = 0; i < size; i++) {
        s+=arr[i];
    }
    
    srand(time(NULL));
    int idx=rand()%s.size();
    
    string str="";
    
    for(int i=0;i<size;i++){
            if(i==idx){
                str+='0';
                i++;
            }
            str+=arr[i];
        }

   
     return s==str?true:false;
}

int main()
{
    int i,j,d,n;
    cout<<"Enter range of message: "<<endl;
    cin>>d;
    cout<<"Enter frames"<<endl;
    cin>> n;
    int msg[n][d];
    cout<<"Enter message: "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <d ; j++) {
            cin>>msg[i][j];
        }
    }
        
    int arr1[n+1][d+1];
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < d ; j++) {
            if (msg[i][j] == 1) {
                count++;
            }
            arr1[i][j]=msg[i][j];
        }
        if(count%2==0){
            arr1[i][d]=0;
        }
        else {
            arr1[i][d]=1;
        }

    }

    for (int i = 0; i < d+1; i++) {
        int sumCol = 0;
            for(int j = 0; j < n; j++){
                sumCol = sumCol + msg[j][i];
            }
            if(sumCol%2==0){
                arr1[n][i]=0;
            }
            else {
                arr1[n][i]=1;
            }
    }

         // implementing 2d parity: 
    for (int i = 0; i < n+1 ; i++) {
        for (int j = 0; j < d+1; j++) {
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }

        for (int i = 0; i < n; i++) {
            int check[d+1];
            for (int j = 0; j < d+1; j++) {
                check[j]=arr1[i][j];
            }
            bool f=transmit(check , d+1);
            if(f==false){
                cout<<"Error detected "<<endl;
                cout<<"Please retrasmit ";
                break;
            }
        }
//        1 0 0 1 1 0 1 0 0 1 0 1 1 1 1 1 0 1 0 1 0 1 0 1 1 0 1 1 1

        cout<<"Recieved signal : "<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                cout<<arr1[i][j]<<" ";
            }
            cout<<" ";
        }
}

