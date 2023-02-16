#include<bits/stdc++.h>
#include<string>
#include<math.h>
using namespace std;

short memory[65536];
string A,B,C,D,E,H,L;

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
    return result;
}

int mem(string loc){
    int decloc = hexToDec(loc);
    return memory[decloc];
}

int main(){
    memset(memory,0,sizeof(memory));
    cout<<"_STUDENT_85"<<endl;
    while(true){
        char in;
        cin>>in;
        switch(in){
            case 'M':
                string loc;
                cin>>loc;
                if(loc.size()>4){
                    cout<<"Error!"<<endl;
                    break;
                }
                string cond="";
                while(cond!="$"){
                    cout<<"M"<<loc<<":"<<decToHex(mem(loc))<<"-";
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
                            string val = ""+cond[cond.size()-2]+cond[cond.size()-1];
                            memory[dec_loc]=hexToDec(val);
                        }
                        loc = increaseHexByOne(loc);
                    }
                }
        }
    }
}