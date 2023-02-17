#include<bits/stdc++.h>
#include<string>
#include<math.h>
using namespace std;

short memory[65536];
short reg[7];
short M;
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

string decToHex(int dec){
    string hex = "";
    int remainder;
    if(dec == 0)
        return "00";
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

int mem(string loc){
    int decloc = hexToDec(loc);
    return memory[decloc];
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

string getPointer(){
    //returns the address of HL pointer
    return decToHex(get_reg('H')) + decToHex(get_reg('L'));
}

short get_M(){
    string HLpointer =decToHex(get_reg('H')) + decToHex(get_reg('L'));
    return mem(HLpointer);
}

void put_M(short val){
    //adds the given value to the memory at HL;
    memory[hexToDec(getPointer())] = val;
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

void runprogram(int loc){
    cout<<"EXECUTING"<<endl;
    int ef = hexToDec("EF");
    while(memory[loc]!=ef){
        string hex_mem = decToHex(memory[loc]);
        // NOP - No Operation
        if(hex_mem == "00"){// NOP
        }
        else if(hex_mem == "41"){//MOV B,C
            reg[1]=reg[2];
        }
        else if(hex_mem == "42"){//MOV B,D
            reg[1]=reg[3];
        }
        else if(hex_mem == "43"){//MOV B,E
            reg[1]=reg[4];
        }
        else if(hex_mem == "44"){//MOV B,H
            reg[1]=reg[5];
        }
        else if(hex_mem == "45"){//MOV B,L
            reg[1]=reg[6];
        }
        else if(hex_mem == "46"){//MOV B,M
            reg[1] = get_M();
        }
        else if(hex_mem == "47"){//MOV B,A
            reg[1]=reg[0];
        }
        else if(hex_mem == "48"){//MOV C,B
            reg[2]=reg[1];
        }
        else if(hex_mem == "4A"){//MOV C,D
            reg[2]=reg[3];
        }
        else if(hex_mem == "4B"){//MOV C,E
            reg[2]=reg[4];
        }
        else if(hex_mem == "4C"){//MOV C,H
            reg[2]=reg[5];
        }
        else if(hex_mem == "4D"){//MOV C,L
            reg[2]=reg[6];
        }
        else if(hex_mem == "4E"){//MOV C,M
            reg[2] = get_M();
        }
        else if(hex_mem == "4F"){//MOV C,A
            reg[2]=reg[0];
        }
        else if(hex_mem == "50"){//MOV D,B
            reg[3]=reg[1];
        }
        else if(hex_mem == "51"){//MOV D,C
            reg[3]=reg[2];
        }
        else if(hex_mem == "53"){//MOV D,E
            reg[3]=reg[4];
        }
        else if(hex_mem == "54"){//MOV D,H
            reg[3]=reg[5];
        }
        else if(hex_mem == "55"){//MOV D,L
            reg[3]=reg[6];
        }
        else if(hex_mem == "56"){//MOV D,M
            reg[3] = get_M();
        }
        else if(hex_mem == "57"){//MOV D,A
            reg[3]=reg[0];
        }
        else if(hex_mem == "58"){//MOV E,B
            reg[4]=reg[1];
        }
        else if(hex_mem == "59"){//MOV E,C
            reg[4]=reg[2];
        }
        else if(hex_mem == "5A"){//MOV E,D
            reg[4]=reg[3];
        }
        else if(hex_mem == "5C"){//MOV E,H
            reg[4]=reg[5];
        }
        else if(hex_mem == "5D"){//MOV E,L
            reg[4]=reg[6];
        }
        else if(hex_mem == "5E"){//MOV E,M
            reg[4] = get_M();
        }
        else if(hex_mem == "5F"){//MOV E,A
            reg[4]=reg[0];
        }
        else if(hex_mem == "60"){//MOV H,B
            reg[5]=reg[1];
        }
        else if(hex_mem == "61"){//MOV H,C
            reg[5]=reg[2];
        }
        else if(hex_mem == "62"){//MOV H,D
            reg[5]=reg[3];
        }
        else if(hex_mem == "63"){//MOV H,E
            reg[5]=reg[4];
        }
        else if(hex_mem == "65"){//MOV H,L
            reg[5]=reg[6];
        }
        else if(hex_mem == "66"){//MOV H,M
            reg[5] = get_M();
        }
        else if(hex_mem == "67"){//MOV H,A
            reg[5]=reg[0];
        }
        else if(hex_mem == "68"){//MOV L,B
            reg[6]=reg[1];
        }
        else if(hex_mem == "69"){//MOV L,C
            reg[6]=reg[2];
        }
        else if(hex_mem == "6A"){//MOV L,D
            reg[6]=reg[3];
        }
        else if(hex_mem == "6B"){//MOV L,E
            reg[6]=reg[4];
        }
        else if(hex_mem == "6C"){//MOV L,H
            reg[6]=reg[5];
        }
        else if(hex_mem == "6E"){//MOV L,M
            reg[6] = get_M();
        }
        else if(hex_mem == "6F"){//MOV L,A
            reg[6]=reg[0];
        }
        else if(hex_mem == "70"){//MOV M,B
            put_M(reg[1]);
        }
        else if(hex_mem == "71"){//MOV M,C
            put_M(reg[2]);
        }
        else if(hex_mem == "72"){//MOV M,D
            put_M(reg[3]);
        }
        else if(hex_mem == "73"){//MOV M,E
            put_M(reg[4]);
        }
        else if(hex_mem == "74"){//MOV M,H
            put_M(reg[5]);
        }
        else if(hex_mem == "75"){//MOV M,L
            put_M(reg[6]);
        }
        else if(hex_mem == "77"){//MOV M,A
            put_M(reg[0]);
        }
        else if(hex_mem == "78"){// Mov A,B
            reg[0]=reg[1];
        }
        else if(hex_mem == "79"){//MOV A,C
            reg[0]=reg[2];
        }
        else if(hex_mem == "7A"){//MOV A,D
            reg[0]=reg[3];
        }
        else if(hex_mem == "7B"){//MOV A,E
            reg[0]=reg[4];
        }
        else if(hex_mem == "7C"){//MOV A,H
            reg[0]=reg[5];
        }
        else if(hex_mem == "7D"){//MOV A,L
            reg[0]=reg[6];
        }
        else if(hex_mem == "7E"){//MOV A,M
            reg[0] = get_M();
        }
        else if(hex_mem == "80"){// ADD B
        }
        else if(hex_mem == "81"){// ADD C
        }
        else if(hex_mem == "82"){// ADD D
        }
        else if(hex_mem == "83"){// ADD E
        }
        else if(hex_mem == "84"){// ADD H
        }
        else if(hex_mem == "85"){// ADD L
        }
        else if(hex_mem == "86"){// ADD M
        }
        else if(hex_mem == "87"){// ADD A
        }
        else if(hex_mem == "88"){// ADC B
        }
        else if(hex_mem == "89"){// ADC C
        }
        else if(hex_mem == "8A"){// ADC D
        }
        else if(hex_mem == "8B"){// ADC E
        }
        else if(hex_mem == "8C"){// ADC H
        }
        else if(hex_mem == "8D"){// ADC L
        }
        else if(hex_mem == "8E"){// ADC M
        }
        else if(hex_mem == "8F"){// ADC A
        }
        else if(hex_mem == "90"){// SUB B
        }
        else if(hex_mem == "91"){// SUB C
        }
        else if(hex_mem == "92"){// SUB D
        }
        else if(hex_mem == "93"){// SUB E
        }
        else if(hex_mem == "94"){// SUB H
        }
        else if(hex_mem == "95"){// SUB L
        }
        else if(hex_mem == "96"){// SUB M
        }
        else if(hex_mem == "97"){// SUB A
        }
        else if(hex_mem == "98"){// SBB B
        }
        else if(hex_mem == "99"){// SBB C
        }
        else if(hex_mem == "9A"){// SBB D
        }
        loc++;
    }
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
                    cout<<decToHex(mem(loc))<<"-";
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
                    cout<<decToHex(get_reg(registe[i]))<<"-";
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
                string loc;
                cin>>loc;
                runprogram(hexToDec(loc));
            }
            else if(in=='T' || in=='t'){//condition for testing the function, remove after testing
                get_M();
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