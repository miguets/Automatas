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

char alpha[15] = {'0','1','2','3','4','5','6','7','8','9','+','-','e','E','.'};

int checkac(string x, int status, int control){
    if((status== q1 or status==q4 or status==q6) and control== 0) cout<<"Cadena Aceptada"<<'\n';
    else cout<<"Cadena No Aceptada"<<'\n';
}

bool valalpha(char x){
    if(x == alpha[0] or x == alpha[1] or x == alpha[2] or x == alpha[3] or x == alpha[4] or x == alpha[5] or x == alpha[6] or x == alpha[7] or x == alpha[8] or x == alpha[9] or x == alpha[10] or x == alpha[11] or x == alpha[12] or x ==alpha[13] or x == alpha[14]) return true;
    else return false;
}

int main(){
    string cade; cin>>cade;
    int s=cade.length(), da, status = q0, control = 0;
    for(int i=0; i<s; i++){
        if(valalpha(cade[i])){
            switch(status){
                case q0: //q0
                    if((isdigit(cade[i]) == 1) or (cade[i]=='-' or cade[i] == '+')) status = q1;
                    else if(cade[i] == 'e' or cade[i] == 'E') status = q7;
                    break;
                case q1: //q1
                    if((isdigit(cade[i]) == 1)) status = q1;
                    else if(cade[i] == '.') status = q2;
                    else if(cade[i] == 'e' or cade[i] == 'E') status = q3;
                    else if(cade[i] == '+' or cade[i] == '-') status = q7;
                    break;
                 case q2:  //q3
                    if((isdigit(cade[i]) == 1)) status = q4;
                    else if(cade[i] == '.' or cade[i] == '-' or cade[i] == '+' or cade[i] == 'e' or cade[i] =='E') status = q7;
                    break;
                case q3:  //q3
                    if(cade[i] == '+' or cade[i] == '-') status = q5;
                    else if(cade[i] == '.') status = q7;
                    else if((isdigit(cade[i]) == 1)) status = q6;
                    break;
                case q4:  //q4
                    if((isdigit(cade[i]) == 1)) status = q4;
                    else if(cade[i] == '.' or cade[i] == '-' or cade[i] == '+') status = q7;
                    else if(cade[i] == 'e' or cade[i] == 'E') status = q3;
                    break;
                case q5:  //q5
                    if((isdigit(cade[i]) == 1)) status = q6;
                    else if(cade[i] == '.' or cade[i] == '-' or cade[i] == '+' or cade[i] == 'e' or cade[i] =='E') status = q7;
                    break;
                case q6:  //q6
                    if((isdigit(cade[i]) == 1)) status = q6;
                    else if(cade[i] == '.' or cade[i] == '-' or cade[i] == '+' or cade[i] == 'e' or cade[i] =='E') status = q7;
                    break;
                case q7:  //q4
                    if((isdigit(cade[i]) == 1) or (cade[i] == '.' or cade[i] == '-' or cade[i] == '+' or cade[i] == 'e' or cade[i] =='E')) status = q8;
                    break;
            }
        }
        else status = q7, control = 1;
        //cout<<'q'<<status<<"  ";    //trace
    }
    checkac(cade, status, control);
    return 0;
}

/* CADENAS ACEPTADAS
+23.25e-3
-3.1416
1234
256.1244E4
-34.65e2
-45.2E+3
*/

/* CADENAS NO ACEPTADAS
12.231.345
45.6E+-4
3.14E2E3
513.12E
3k45.1E-2
34+12e2
12.45E+1.2
*/