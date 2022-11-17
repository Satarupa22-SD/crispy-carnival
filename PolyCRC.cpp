#include<bits/stdc++.h>
#include<string>
using namespace std;

string polynomial(string str){
    string poly="";
    reverse(str.begin(),str.end());
    for(int i=0;i<str.size();i++){
        if(str[i]=='1' && i==0){
            poly+="1+";
        }else if(str[i]=='1'){
            poly+=to_string(i);poly+="^x+";
        }
    }
    reverse(poly.begin(),poly.end());
    poly[0]='.';
    return poly;
}

int ind(string data){
    int i=0,ans;
    for(i=0;i<data.size();i++){
        if(data[i]=='1'){
             return i;
        }
    }
    return data.size();
}
string remainder(string data,string key){
    int f1=ind(data);
    if(data.size()-f1<=3){
        return data;
    }
    for(int i=0;i<key.size();i++){
        data[f1] = (data[f1]==key[i])?'0':'1';
        f1++;
    }
    return remainder(data,key);
}

int main(){
    string data,key;
    cout<<"Enter Message : ";
    cin>>data;
    cout<<"Enter Getter : ";
    cin>>key;
    cout<<"In Polynomial Form :-\n";
    cout<<"\nMessage : "<<polynomial(data);
    cout<<"\nKey : "<<polynomial(key);
    int n=data.size();
    string rem = remainder(data+"000",key);
    string r = rem.substr(rem.size()-3, 3);
    data+=r;
    cout<<"\nRedundand bit is : "<<r;
    cout<<"\nEncoded data is : "<<data;
    int id = rand()%10;
    cout<<"\nError bit at : "<<id;
    data[id] = (data[id]=='1')?'0':'1';
    cout<<"\nRecievers Side Message : "<<data;
    // string check
    int ans = stoi(remainder(data,key));
    if(ans==0){
        cout<<"\nMessage Accepted";
    }else{
        cout<<"\nRecieved Erranious Message";
    }
    return 0;
}
