// Lab-03
Single Bit Parity


#include <iostream>
using namespace std;

bool parity(string s){
    int cnt=0;
    
    for(int i=0; i<s.length();i++){
        if(s[i]=='1'){
            cnt++;
        }
    }
    
    if(cnt%2==0){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string msg;
    cout<<"Enter Message :"<<endl;
    cin>>msg;
    
    if(parity(msg)){
        msg=msg+'0';
    }else{
        msg=msg+'1';
    }
    
    cout<<"Message Sent by Sender :";
    cout<<msg<<endl;
    
    
    //error 
    
    srand(time(NULL));
    int i = rand() % msg.size();
    
    if(msg[i]=='1'){
        msg[i]='0';
    }
    else if(msg[i]=='0'){
        msg[i]='1';
    }
    
    cout<<"\nMessage Recieved :";
    cout<<msg;
    
    if(parity(msg)){
        cout<<"\nErrorless message";
    }
    else{
        cout<<"\nError is present in message";
    }
    return 0;
}

