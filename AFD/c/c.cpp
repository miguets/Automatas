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


/*Un  AFD  que  acepte  cadenas  que  contengan  dos  o  más símbolos consecutivos iguales*/
char alpha[4] = {'a','b', 'c', 'd'};

int checkac(string x, int status, int control){
    if(status== q5 and control== 0) cout<<"Cadena Aceptada"<<'\n';
    else cout<<"Cadena No Aceptada"<<'\n';
}

bool valalpha(char x){
    if(x == alpha[0] or x == alpha[1] or x == alpha[2] or x == alpha[3]) return true;
    else return false;
}

int main(){
    string cade; cin>>cade;
    int s=cade.length(), da, status = q0, control = 0;
    for(int i=0; i<s; i++){
        if(valalpha(cade[i])){
            switch(status){
                case q0: //q0
                    if(cade[i] == 'a') status = q1;
                    else if(cade[i] == 'b') status = q2;
                    else if(cade[i] == 'c') status = q3;
                    else if(cade[i] == 'd') status = q4;
                    break;
                case q1: //q1
                    if(cade[i] == 'a') status = q5;
                    else if(cade[i] == 'b') status = q2;
                    else if(cade[i] == 'c') status = q3;
                    else if(cade[i] == 'd') status = q4;
                    break;
                case q2:  //q2
                    if(cade[i] == 'a') status = q1;
                    else if(cade[i] == 'b') status = q5;
                    else if(cade[i] == 'c') status = q3;
                    else if(cade[i] == 'd') status = q4;
                    break;
                case q3:  //q3
                    if(cade[i] == 'a') status = q1;
                    else if(cade[i] == 'b') status = q2;
                    else if(cade[i] == 'c') status = q5;
                    else if(cade[i] == 'd') status = q4;
                    break;
                case q4:  //q4
                    if(cade[i] == 'a') status = q1;
                    else if(cade[i] == 'b') status = q2;
                    else if(cade[i] == 'c') status = q3;
                    else if(cade[i] == 'd') status = q5;
                    break;
                case q5:  //q5
                    if(cade[i] == 'a') status = q5;
                    else if(cade[i] == 'b') status = q5;
                    else if(cade[i] == 'c') status = q5;
                    else if(cade[i] == 'd') status = q5;
                    break;
            }
        }
        else status = q0, control = 1;
        //cout<<'q'<<status<<"  ";    //trace
    }
    checkac(cade, status, control);
    return 0;
}