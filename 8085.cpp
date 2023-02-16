#include<bits/stdc++.h>
#include<string>
#include<math.h>
using namespace std;

short memory[65536];
short reg[7];
string F="00000000";

int hexToDec(string hex){
    int dec = 0;
    int base = 1;
    for (int i = hex.length() - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9'){
            dec += (hex[i] - '0') * base;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F'){
            dec += (hex[i] - 'A' + 10) * base;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f'){
            dec += (hex[i] - 'a' + 10) * base;
        }
        base *= 16;
    }
    return dec;
}

short get_reg(char r='A'){
    if(r == 'A'){
        return reg[0];
    }
    else if(r == 'B'){
        return reg[1];
    }
    else if(r == 'C'){
        return reg[2];
    }
    else if(r == 'D'){
        return reg[3];
    }
    else if(r == 'E'){
        return reg[4];
    }
    else if(r == 'H'){
        return reg[5];
    }
    else if(r == 'L'){
        return reg[6];
    }
    else{
        throw 101;
        return -1;
    }

}

string decToHex(int dec){
    string hex = "";
    int remainder;
    while (dec > 0) {
        remainder = dec % 16;
        if(remainder < 10){
            hex = char(remainder + 48) + hex;
        }
        else{
            hex = char(remainder + 55) + hex;
        }
        dec /= 16;
    }
    return hex;
}

string increaseHexByOne(string hex){
    int dec = stoi(hex, 0, 16);
    dec += 1;
    string result = "";
    while (dec != 0) {
        int remainder = dec % 16;
        if (remainder < 10){
            result += char(remainder + 48);
        }
        else{
            result += char(remainder + 55);
        }
        dec /= 16;
    }
    reverse(result.begin(), result.end());
    if (hexToDec(result) > 65535){
        throw 103;
    }
    return result;
}

int mem(string loc){
    int decloc = hexToDec(loc);
    return memory[decloc];
}

void runprogram(int loc){

}

int main(){
    memset(memory,0,sizeof(memory));
    cout<<"_STUDENT_85"<<endl;
    while(true){
        try{
            char in;
            cin>>in;
            if(in=='M' || in=='m'){
                string loc;
                cin>>loc;
                if(loc.size()>4){
                    throw 102;
                    cout<<"Error!"<<endl;
                    break;
                }
                string cond="";
                getline(cin,cond);// to flush the std input
                while(cond!="$"){
                    cout<<"M"<<loc<<":";
                    if(mem(loc)==0){
                        cout<<"00"<<"-";
                    }
                    else{
                        cout<<decToHex(mem(loc))<<"-";
                    }
                    getline(cin,cond);
                    if(cond.empty() || (cond.size() == 1 && cond[0] == '\n')){
                        loc=increaseHexByOne(loc);
                    }
                    else if(cond!="$"){
                        int l = cond.size();
                        if(l==1 || l==2){
                            int dec_loc = hexToDec(loc);
                            memory[dec_loc]=hexToDec(cond);
                        }
                        else{
                            int dec_loc = hexToDec(loc);
                            string val = ""+cond[l-2]+cond[l-1];
                            memory[dec_loc]=hexToDec(val);
                        }
                        loc = increaseHexByOne(loc);
                    }
                }
            }
            else if(in=='R' || in=='r'){
                int i=0;
                string cond;
                string registe = "ABCDEHL";
                getline(cin,cond);//to flush the std input
                while(i < 7){
                    cout<<registe[i]<<":";
                    if(get_reg(registe[i])==0){
                        cout<<"00"<<"-";
                    }
                    else{
                        cout<<decToHex(get_reg(registe[i]))<<"-";
                    }
                    getline(cin,cond);
                    if(cond != "$"){
                        int l = cond.size();
                        if(l==1 || l==2){
                            reg[i]=hexToDec(cond);
                        }
                        else if(l!=0){
                            char val[3];
                            val[0] = cond[l-2];
                            val[1] = cond[l-1];
                            val[2] = '\0';
                            reg[i]=hexToDec(val);
                        }
                        i++;
                    }
                    else if(cond == "$"){
                        break;
                    }
                    else{
                        cout<<"ERROR OCCURED"<<endl;
                        break;
                    }
                }
            }
            else if(in=='G' || in=='g'){
                cout<<"Location:";
                string loc;
                runprogram(hexToDec(loc));
            }
        }
        catch(int errorCode){
            switch(errorCode){
                case 101:
                    cout<<"\n"<<errorCode<<"Unrecognized register \n Press Enter"<<endl;
                    break;
                case 102:
                    cout<<"\n"<<errorCode<<"Unrecognized Memory Location \n Press Enter"<<endl;
                    break;
                case 103:
                    cout<<"\n"<<errorCode<<"Memory Location Exceeded \n Press Enter"<<endl;
                    break;
            }
        }
    }
}