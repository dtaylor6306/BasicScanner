#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

/*
    TODO LIST

[x] begin
[x] end
[x] Read
[x] write
[x] IntLiteral
[] ID
[] EOF   -----maybe done?

\t ==  9
\n ==  10
blank space ==  32

*/

int main(){
    ifstream in("input.txt");
    char ch;
    string line;
    string newstring;
    
    while(getline(in,line)){
        for (int i = 0; i< line.length(); i++){
            if(line[i] == '('){
                cout << "LParen" << endl;
            }
            else if(line[i] == ')'){
                cout << "Rparen" << endl;
            }
            else if(line[i] == ','){
                cout << "Comma" << endl;
            }
            else if(line[i] == ';'){
                cout << "SemiColon" << endl;
                //getline(in,newstring);
                //cout << newstring << endl;
            }
            else if(line[i] == '+'){
                cout << "PlusOp" << endl;
            }
            else if(line[i] == '-'){
                if(line[i+1] == '-'){
                    cout << "Comment!!!!" << endl;
                    break;
                }
                else{
                    cout << "MinusOp" << endl;
                }
            }
            else if(line[i] == ':'){
                if(line[i+1] == '='){
                    cout << "AssignOp" << endl;
                }
            }
            else if(line[i] == 'W' && line[i+1] == 'R' && line[i+2] == 'I' && line[i+3] == 'T' && line[i+4] == 'E'){
                cout << "WriteSym" << endl;  
            }
            else if(line[i] == 'R' && line[i+1] == 'E' && line[i+2] == 'A' && line[i+3] == 'D'){
                cout << "ReadSym" << endl;  
            }
            else if(line[i] == 'B' && line[i+1] == 'E' && line[i+2] == 'G' && line[i+3] == 'I' && line[i+4] == 'N'){
                cout << "BegSym" << endl;  
            }
            else if(line[i] == 'E' && line[i+1] == 'N' && line[i+2] == 'D'){
                cout << "EndSym" << endl;  
            }
            else if(isdigit(line[i]) && !isalpha(line[i - 1])){
                while(isdigit(line[i])){
                    i++;
                }
                if(!isalpha(line[i])){
                    cout << "IntLiteral" << endl;
                }
            }

        }
    }

}




