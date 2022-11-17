#include<bits/stdc++.h>
using namespace std;

string xor1(string a , string b)
{
    int n = b.length();
    
    string ans="";

    for(int i=1 ; i<n ; i++)
    {
        if(a[i]==b[i]){
            ans=ans+"0";
        }
        else{
            ans=ans+"1";
        }
    }

    return ans;
}

string mod2Division(string msg , string g)
{
    int n = msg.length();

    int k =g.length();

    string rem = msg.substr(0, k);

    while (k<n)
    {
        if(rem[0] =='1'){
            rem = xor1(g ,rem) + msg[k] ;
        }
        else{
            rem = xor1(std::string(k ,'0'), rem) + msg[k];
        }

        k+=1;
    }

    if(rem[0]=='1'){
        rem = xor1(g , rem);
    }
    else{
         rem = xor1(std::string(k, '0'), rem) ;
    }

    return rem;
}

string encodeMessage(string msg , string g)
{
    int len = g.length();
     
    // Add n-1 zeroes at end of msg
    string appended_data = (msg + std::string( len - 1, '0'));
     
    string remainder = mod2Division(appended_data, g);
     
    // Add remainder in the original data
    //string codeword = msg + remainder;
    cout << "Remainder : "<< remainder << "\n";
    

    return remainder;
}

int main()
{
    string msg;
    string g;

    cout<<"Enter the message :"<<endl;
    cin>>msg;

    cout<<"Enter the generator-bit :"<<endl;
    cin>>g;

    
    cout<<"\nAt Sender's Side :"<<endl;
    string remainder = encodeMessage(msg , g);
    cout << "\nEncoded Data (Message + Remainder) :"<< msg + remainder << "\n";

    string codeword = msg + remainder;
    
    srand(time(NULL));
    int id = rand()%10;
    cout<<"\nError bit at : "<<id;
    codeword[id] = (codeword[id]=='1')?'0':'1';
    
    cout<<"\nAt Reciever's side :"<<endl;
    cout<<"\nRecievers Side Message : "<<codeword<<endl;
    
    
    int rem = stoi(encodeMessage(codeword , g));

    if(rem==0){
        cout<<"Message is correct";
    }
    else{
        cout<<"Message is incorrect";
    }
    

}
