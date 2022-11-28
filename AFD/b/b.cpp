#include<bits/stdc++.h>
/*
#include<iostream>
#include<string>
*/
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
/*Un AFD que reconozca el lenguaje formado por cadenas que contengan un número par  de  símbolos 0,  y  sin  símbolos 1  sucesivos. */
// countc%2==0
// anso < 2
int checkac(string x, int status){ //tam, ansone, diffalpha, countz
    if(status== q4 or status== q6) cout<<"Cadena Aceptada"<<'\n';
    else cout<<"Cadena No Aceptada"<<'\n';
}

bool valalpha(char x){
    if(x == alpha[0] or x == alpha[1]) return true;
    else return false;
}

int main(){
    //int n; cin>>n; for(int j=0; j<n; j++){
    string cade; cin>>cade;
    int s=cade.length(), da, status = q0;
    for(int i=0; i<s; i++){
        if(valalpha(cade[i])){
            switch(status){
                case q0: //q0
                    if(cade[i]=='0') status = q2;
                    else if(cade[i]=='1') status = q1;
                    break;
                case q1: //q1
                    if(cade[i]=='0') status= q2;
                    else if(cade[i]=='1') status = q3;
                    break;
                case q2:  //q2
                    if(cade[i]=='0') status= q4;
                    else if(cade[i]=='1') status = q7;
                    break;
                case q3:  //q3
                    if(cade[i]=='0') status= q3;
                    else if(cade[i]=='1') status = q3;
                    break;
                case q4:  //q4
                    if(cade[i]=='0') status= q5;
                    else if(cade[i]=='1') status = q6;
                    break;
                case q5:  //q5
                    if(cade[i]=='0') status= q4;
                    else if(cade[i]=='1') status = q9;
                    break;
                case q6:  //q6
                    if(cade[i]=='0') status= q8;
                    else if(cade[i]=='1') status = q3;
                    break;
                case q7:   //q7
                    if(cade[i]=='0') status= q4;
                    else if(cade[i]=='1') status = q3;
                    break;
                case q8:   //q8
                    if(cade[i]=='0') status= q4;
                    else if(cade[i]=='1') status = q9;
                    break;
                case q9:  //q9
                    if(cade[i]=='0') status= q4;
                    else if(cade[i]=='1') status = q3;
                    break;
            }
        }
        else status = q3;

        //cout<<'q'<<status<<"  ";     //trace
    }
    checkac(cade, status);
    //}
    return 0;
}