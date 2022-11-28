/*
Un afd cuyo alfabeto sea {0,1} que va a aceptar las cadenas que contengan "001", 
siempre y cuando no contengan dos unos contiguos "11",un uno con dos ceros contiguos "100" y su numero total de ceros sea un numero par.
*/
#include<bits/stdc++.h>

using namespace std;

#define q0 0
#define q1 1
#define q2 2
#define q3 3
#define q4 4
#define q5 5
#define q6 6
#define q7 7
#define q8 8
#define q9 9
#define q10 10

char alpha[2] = {'0','1'};

int checkac(string x, int status, int control){
    if((status== q3 or status== q8 or status== q9) and control== 0) cout<<"Cadena Aceptada"<<'\n';
    else cout<<"Cadena No Aceptada"<<'\n';
}

bool valalpha(char x){
    if(x == alpha[0] or x == alpha[1]) return true;
    else return false;
}

int main(){
    string cade; cin>>cade;
    int s=cade.length(), da, status = q0, control = 0;
    for(int i=0; i<s; i++){
        if(valalpha(cade[i])){
            switch(status){
                case q0: //q0
                    if(cade[i] == '0') status = q1;
                    else if(cade[i] == '1') status = q5;
                    break;
                case q1: //q1
                    if(cade[i] == '0') status = q2;
                    else if(cade[i] == '1') status = q5;
                    break;
                case q2:  //q2
                    if(cade[i] == '0') status = q6;
                    else if(cade[i] == '1') status = q3;
                    break;
                case q3:  //q3
                    if(cade[i] == '0') status = q4;
                    else if(cade[i] == '1') status = q5;
                    break;
                case q4:  //q4
                    if(cade[i] == '0') status = q5;
                    else if(cade[i] == '1') status = q1;
                    break;
                case q5:  //q5
                    if(cade[i] == '0') status = q5;
                    else if(cade[i] == '1') status = q5;
                    break;
                case q6:  //q6
                    if(cade[i] == '0') status = q2;
                    else if(cade[i] == '1') status = q7;
                    break;
                case q7:  //q4
                    if(cade[i] == '0') status = q8;
                    else if(cade[i] == '1') status = q5;
                    break;
                case q8:  //q5
                    if(cade[i] == '0') status = q7;
                    else if(cade[i] == '1') status = q9;
                    break;
                case q9:  //q6
                    if(cade[i] == '0') status = q6;
                    else if(cade[i] == '1') status = q5;
                    break;
            }
        }
        else status = q0, control = 1;
        //cout<<'q'<<status<<"  ";    //trace
    }
    checkac(cade, status, control);
    return 0;
}

/* CADENAS ACEPTADAS:
001
00001
000101
0001010101010
00010101010101
00000000001
00000000010
*/

/* CADENAS NO ACEPTADAS:
0001
0011
1010
10100
100100
1001001
0101010101011
01010101
*/