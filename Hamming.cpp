// Hamming Code

#include<bits/stdc++.h>
using namespace std;

int parityCheck(string s)
{
    int cnt=0;
    
    for(int i=0; i<s.length() ;i++){
        if(s[i]=='1'){
            cnt++;
        }
    }
    
    if(cnt%2==0){
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
    string msg;

    cout<<"Enter 7-bit message :";
    cin>>msg;
    
    string P1="";
    string P2="";
    string P4="";
    
    reverse(msg.begin(), msg.end());
    
    //p1=1,3,5,7
    P1=P1+msg[0]+msg[2]+msg[4]+msg[6];
    
    //p2=2,3,6,7
    P2=P2+msg[1]+msg[2]+msg[5]+msg[6];
    
    //p4=4,5,6,7
    P4=P4+msg[3]+msg[4]+msg[5]+msg[6];
    
    int parity[3];
    
    parity[0] = parityCheck(P1);
    parity[1] = parityCheck(P2);
    parity[2] = parityCheck(P4);
    
    cout<<parity[2]<<parity[1]<<parity[0];
    
    int pos = pow(2,2)*parity[2] + pow(2,1)*parity[1] + pow(2,0)*parity[0];
    
    cout<<"\nError at position = "<<pos<<endl;
    
    if(msg.at(pos-1)=='1'){
        msg.replace(pos-1 , 1 , "0");
        reverse(msg.begin(), msg.end());
       cout<<"Correct message = "<< msg;
    }
    
    else if(msg.at(pos-1)=='0'){
        msg.replace(pos-1 , 1 , "1");
        reverse(msg.begin(), msg.end());
       cout<<"Correct message = "<< msg;
    }
    
    return 0;
}
