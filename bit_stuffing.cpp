//Lab 1 
Bit-Stuffing 

#include<iostream>
#include <string>
using namespace std;

string bitStuffing(string msg)
{
    int count = 0 ;
    string s = "";
    
    for (int i = 0; i < msg.length(); i++) {
        char ch = msg.at(i);
        if (ch == '1') {
            count++;
            if (count < 5)
                s = s + ch;
            else {
                s = s + ch + '0';
                count = 0;
            }
        }
        else {
            s = s + ch;
            count = 0;
        }
    }

    return s;

}

string bitDestuffing(string msg)
{
    int count = 0 ;
    string s = "";

    for (int i = 0; i < msg.length(); i++) {
        char ch = msg.at(i);
        if (ch == '1') {
            count++;
            if (count < 5)
                s = s + ch;
            else {
                i++;
                count = 0;
            }
        }
        else {
            s = s + ch;
            count = 0;
        }
    }
    return s;

}

int main()
{
    string msg;
    cout<<"Enter the message :"<<endl;
    getline(cin , msg);
    
    string ch = bitStuffing(msg);
    
    cout<<"After Stuffing = "<< ch<<endl;
    
    cout<<"After De-Stuffing = "<< bitDestuffing(ch);

}
