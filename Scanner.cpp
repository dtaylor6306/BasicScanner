#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>

using namespace std;

/*
    TODO LIST

[x] begin
[x] end
[x] Read
[x] write
[x] IntLiteral
[x] ID  isalpha(line[i]) && 
[] EOF   -----maybe done?

\t ==  9
\n ==  10
blank space ==  32

*/

int main(int argc,char ** argv){
    ifstream in(argv[1]);
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
                    i++;
                    cout << "AssignOp" << endl;
                }
            }
            else if(line[i] == 'W' && line[i+1] == 'R' && line[i+2] == 'I' && line[i+3] == 'T' && line[i+4] == 'E'){
                cout << "WriteSym" << endl;  
                i += 4;
            }
            else if(line[i] == 'R' && line[i+1] == 'E' && line[i+2] == 'A' && line[i+3] == 'D'){
                cout << "ReadSym" << endl;
                i += 3;  
            }
            else if(line[i] == 'B' && line[i+1] == 'E' && line[i+2] == 'G' && line[i+3] == 'I' && line[i+4] == 'N'){
                cout << "BegSym" << endl;
                i += 4;  
            }
            else if(line[i] == 'E' && line[i+1] == 'N' && line[i+2] == 'D'){
                cout << "EndSym" << endl; 
                i += 2; 
            }
            else if(isdigit(line[i]) && !isalpha(line[i - 1]) && line[i-1] != '_'){
                while(isdigit(line[i])){
                    i++;
                }
                if(!isalpha(line[i])){
                    cout << "IntLiteral" << endl;
                    i--;
                }
                else{
                    while(isalpha(line[i]) || line[i] == '_' || isdigit(line[i])){
                        i++;
                    }
                    i--;
                    cout << "ID" << endl;
                }
            }
            else if(isalpha(line[i])){
                while(isalpha(line[i]) || line[i] == '_' || isdigit(line[i])){
                    i++;
                }
                i--;
                cout << "ID" << endl;
            }
            else if(line[i] == '_'){
                while(isalpha(line[i]) || line[i] == '_' || isdigit(line[i])){
                    i++;
                }
                i--;
                cout << "ID" << endl;
            }

        }
    }

}




