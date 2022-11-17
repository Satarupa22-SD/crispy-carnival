//Lab 2 
Character-Stuffing 

// 24.08.22

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string msg;
    int j=0;
    char flag='Z';
    char esc = '.';
    char ch;
    string ecodemsg="";
    int count=0;
    cout<<"Enter the message :";
    getline(cin , msg);

    //Character Stuffing Method

    for(int i=0;i<msg.length() ;i++)
    {
        ch=msg.at(i);

        if(ch==flag){
            ecodemsg=ecodemsg + esc + ch;
        }
        else if(ch==esc){
            count++;
            if(count==2){
                ecodemsg = ecodemsg +esc+ch;
                count=0;
            }
            else{
                ecodemsg = ecodemsg +esc + ch;
            }    
        }
        else{
            ecodemsg = ecodemsg+ch;
        }
    }

    cout<<endl;
    cout<<"Sender's Side :"<<endl;
    cout<<endl;
    cout<<"Original Message:"<<msg<<endl;
    cout<<"After Character Stuffing : "<< flag+ecodemsg+flag;

    //De-Stuffing Method
    
    string decodedStr="";
    int i=0;
        while(i<ecodemsg.length())
        {
            char ch = ecodemsg.at(i);
            if(i<ecodemsg.length()-1 && ch==ecodemsg.at(i+1))
            {
                decodedStr=decodedStr+ch;
                i=i+2;
            }
            else if(i<ecodemsg.length()-1 && ecodemsg.at(i+1)=='Z')
            {
                decodedStr=decodedStr+ecodemsg.at(i+1);
                i=i+2;
            }
            else{
                decodedStr=decodedStr+ch;
                i++;
            } 
        }
    cout<<endl;
    cout<<"Reciver's Side :"<<endl;
    cout<<endl;
    cout<<"Recieved Message :"<<ecodemsg<<endl;
    cout<<"Decoded Message: "<< decodedStr;

}
