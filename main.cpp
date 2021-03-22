#include <iostream>
#include <string>
#include <cmath>

float GetOperand(std::string &Stack){
    std::string Number;
    for (int i=Stack.size()-1; i>-1; i--){
        if (Stack[i]==' '){
            Number=Stack.substr(i+1);
            Stack=Stack.substr(0, i);
            break;
        }
    }
    float OperandOut=std::stof(Number);
    return OperandOut;
}

int main() {
    std::cout << "Hello! Please, enter your expression placing a space after numbers: " << std::endl;
    std::string Expression;
    std::getline(std::cin, Expression);
    std::string Stack;
    std::string StringOut;
    std::string x;
    for (int i = 0; i < Expression.size(); i++) {
        switch (Expression[i]) {
            case '+':
                while ((Stack[Stack.size() - 1] != '(') && (Stack[Stack.size() - 1] != ')') && (!Stack.empty())) {
                    StringOut += ' ';
                    StringOut += Stack[Stack.size() - 1];
                    Stack = Stack.substr(0, Stack.size() - 1);
                }
                Stack += '+';
                break;
            case '-':
                while ((Stack[Stack.size() - 1] != '(') && (Stack[Stack.size() - 1] != ')') && (!Stack.empty())) {
                    StringOut += ' ';
                    StringOut += Stack[Stack.size() - 1];
                    Stack = Stack.substr(0, Stack.size() - 1);
                }
                Stack += '-';
                break;
            case '*':
                while ((Stack[Stack.size() - 1] != '(') && (Stack[Stack.size() - 1] != ')') &&
                       (Stack[Stack.size() - 1] != '+') &&
                       (Stack[Stack.size() - 1] != '-') && (!Stack.empty())) {
                    StringOut += ' ';
                    StringOut += Stack[Stack.size() - 1];
                    Stack = Stack.substr(Stack.size() - 1);
                }
                Stack += '*';
                break;
            case '/':
                while ((Stack[Stack.size() - 1] != '(') && (Stack[Stack.size() - 1] != ')') &&
                       (Stack[Stack.size() - 1] != '+') &&
                       (Stack[Stack.size() - 1] != '-') && (!Stack.empty())) {
                    StringOut += ' ';
                    StringOut += Stack[Stack.size() - 1];
                    Stack = Stack.substr(0, Stack.size() - 1);
                }
                Stack += '/';
                break;
            case '(':
                Stack += '(';
                break;
            case ')':
                while (Stack[Stack.size() - 1] != '(') {
                    StringOut += ' ';
                    StringOut += Stack[Stack.size() - 1];
                    Stack = Stack.substr(0, Stack.size() - 1);
                }
                Stack = Stack.substr(0, Stack.size() - 1);
                break;
            case '^':
                while ((Stack[Stack.size() - 1] != '(') && (Stack[Stack.size() - 1] != ')') &&
                       (Stack[Stack.size() - 1] != '+') && (Stack[Stack.size() - 1] != '*') &&
                       (Stack[Stack.size() - 1] != '/') &&
                       (Stack[Stack.size() - 1] != '-') && (!Stack.empty())) {
                    StringOut += ' ';
                    StringOut += Stack[Stack.size() - 1];
                    Stack = Stack.substr(0, Stack.size() - 1);
                }
                Stack += '^';
                break;
            case 'p': //expect writing pi like 'pi'
                StringOut += ' ';
                StringOut += "3.142";
                i++;
                break;
            case 'e':
                StringOut += ' ';
                StringOut += "2.718";
                break;
            case 'x':
                std::cout << "Please input x" << std::endl;
                std::getline(std::cin, x);
                StringOut += ' ';
                StringOut += x;
                break;
            case ' ':
                break;
            default:
                std::string CurrentString = Expression.substr(i, Expression.size() - i);
                std::string::size_type n = CurrentString.find(' ');
                if (n == std::string::npos) {
                    StringOut += ' ';
                    StringOut += CurrentString;
                    i += CurrentString.size() - 1;
                } else {
                    StringOut += ' ';
                    StringOut += CurrentString.substr(0, n);
                    i += CurrentString.substr(0, n).size() - 1;
                }
                break;
        }
    }
    while (!Stack.empty()) {
        StringOut += ' ';
        StringOut += Stack[Stack.size() - 1];
        Stack = Stack.substr(0, Stack.size() - 1);
    }


    std::string Result;
    Stack = "";
    float Operand1,
            Operand2;
    for (int i = 0; i < StringOut.size(); i++) {
        switch (StringOut[i]) {
            case ' ':
                break;
            case '+':
                Operand1=GetOperand(Stack);
                Operand2=GetOperand(Stack);
                Operand1=Operand1+Operand2;
                Result=std::to_string(Operand1);
                Stack+=' ';
                Stack+=Result;
                break;
            case '-':
                Operand1=GetOperand(Stack);
                Operand2=GetOperand(Stack);
                Operand1=Operand2-Operand1;
                Result=std::to_string(Operand1);
                Stack+=' ';
                Stack+=Result;
                break;
            case '*':
                Operand1=GetOperand(Stack);
                Operand2=GetOperand(Stack);
                Operand1=Operand1*Operand2;
                Result=std::to_string(Operand1);
                Stack+=' ';
                Stack+=Result;
                break;
            case '/':
                Operand1=GetOperand(Stack);
                Operand2=GetOperand(Stack);
                Operand1=Operand2/Operand1;
                Result=std::to_string(Operand1);
                Stack+=' ';
                Stack+=Result;
                break;
            case '^':
                Operand1=GetOperand(Stack);
                Operand2=GetOperand(Stack);
                Operand1=pow(Operand2, Operand1);
                Result=std::to_string(Operand1);
                Stack+=' ';
                Stack+=Result;
                break;
            default:
                std::string Operand = StringOut.substr(i, StringOut.size() - i);
                std::string::size_type n = Operand.find(' ');
                if (n == std::string::npos) {
                    Stack += ' ';
                    Stack += Operand;
                    i += Operand.size() - 1;
                } else {
                    Stack += ' ';
                    Stack += Operand.substr(0, n);
                    i += Operand.substr(0, n).size() - 1;
                }
                break;
        }
    }
    std::cout<<Stack.substr(1)<<std::endl;
    return 0;
}
