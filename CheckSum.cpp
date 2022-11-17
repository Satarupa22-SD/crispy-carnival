// Internet CheckSum

#include<bits/stdc++.h>
using namespace std;

 string add(string a,string b){
    int c=0;
    string ans="";
    for(int i=a.size()-1;i>=0;i--){
        
        if(a[i]=='1' && b[i]=='1'){
            ans+= (c==1)?'1':'0';
            c=1;
        }
        else if((a[i]=='1' && b[i]=='0') || (a[i]=='0' && b[i]=='1')){
            if(c==1){ ans+='0'; c=1;}
            else{ans+='1';}
            
        }
        else if(a[i]=='0' && b[i]=='0'){
            if(c==1){ ans+='1'; c=0;}
            else{ans+='0';}
           
        }
    }
    reverse(ans.begin(),ans.end());
    if(c==1){ ans=add(ans,"00000001");}
    return ans;
 }
 
 string complement(string a){
    for (int i = 0; i < a.length(); i++) {
        if (a.at(i) == '0')
            a.at(i) = '1';
        else
            a.at(i) = '0';
    }
 
    return a;
}
 
 int main(){
    int n,m;
    cout<<"Enter no. of frames : ";
    cin>>n;
    vector<string> arr;
    string s;
    cout<<"Enter Message :-"<<endl;
    for(int i=0;i<n;i++){
        cin>>s;
        arr.push_back(s);
    }
    string ans = arr[0];
    for(int i=1;i<n;i++){
        ans = add(ans,arr[i]);
    }
    
    //cout<<"tmp ans :"<<ans<<endl;
    
    //1's complement
    cout<<"checksum = "<<complement(ans)<<endl;
    
    arr.push_back(complement(ans));         // adding checksum at sender's side
    
    
    string sum = arr[0];
    for(int i=1;i<n+1;i++){
        sum = add(sum,arr[i]);
    }
    
    //cout<<"tmp ans :"<<sum<<endl;
    
    
    cout<<"At Reciever's Side Message recieved = "<<endl;
    
    for(int i=0;i<n+1;i++){
        cout<<arr[i]<<" ";
    }
    
    if(stoi(complement(sum))== 0){
        cout<<"\nMessage is error free ."<<endl;
    }
    
    return 0;
 }
