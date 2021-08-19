#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
using namespace std;

int main(/*int argc, char* argv[]*/)
{
    setlocale(LC_ALL,"rus");
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    char title[30] = "It's your sandbox";
    CharToOemA(title,title);
    SetConsoleTitleA(title);
    SetConsoleTextAttribute(hout,FOREGROUND_RED);

    char cmd[51];
    //strcpy_s(cmd, "cd");
    cout << "Your goal - run cmd(powershell or another shell)!\n" << endl;
    
    while (1)
    {
    lol:
        cout << "sandbox_for_you>";
        gets_s(cmd,50);
        system("cls");
            for (int i = 0; i < sizeof(cmd); i++) //security_check
            {
                if (i > 3)
                {
                    if ((cmd[i] == ' ' || cmd[i] == '(') && (cmd[i + 1] == 'c' || cmd[i + 1] == 'C') && (cmd[i + 2] == 'm' || cmd[i + 2] == 'M') && (cmd[i + 3] == 'd' || cmd[i + 3] == 'D'))
                    {
                        cout << "Недопустимая команда!\n";
                        goto lol;
                    }
                }
                // cmd | cmd.exe
                if ((cmd[i] == 'c' || cmd[i] == 'C') && (cmd[i + 1] == 'm' || cmd[i + 1] == 'M') && (cmd[i + 2] == 'd' || cmd[i + 2] == 'D') && (cmd[i+3] == ' ' || cmd[i+3] == NULL || ((cmd[i+3] == '.') && (cmd[i+4] == 'e' || cmd[i+4] == 'E') && (cmd[i + 5] == 'x' || cmd[i + 5] == 'X') && (cmd[i + 6] == 'e' || cmd[i + 6] == 'E')) || cmd[i + 3] == ',' || cmd[i + 3] == ';' || cmd[i + 3] == '(' || cmd[i + 3] == ')' || cmd[i + 3] == '^' || cmd[i + 3] == '&' || cmd[i + 3] == '\"') || cmd[i + 3] == '\'')
                {
                    cout << "Недопустимая команда!\n";
                    goto lol;
                }
                //powershell | powershell.exe
                if ((cmd[i] == 'p' || cmd[i] == 'P') && (cmd[i + 1] == 'o' || cmd[i + 1] == 'O') && (cmd[i+2] == 'w' || cmd[i+2] == 'W') && (cmd[i + 3] == 'e' || cmd[i + 3] == 'E') && (cmd[i + 4] == 'r' || cmd[i + 4] == 'R') && (cmd[i + 5] == 's' || cmd[i + 5] == 'S') && (cmd[i + 6] == 'h' || cmd[i + 6] == 'H') && (cmd[i + 7] == 'e' || cmd[i + 7] == 'E') && (cmd[i + 8] == 'l' || cmd[i + 8] == 'L') && (cmd[i + 9] == 'l' || cmd[i + 9] == 'L') && (cmd[i + 10] == ' ' || cmd[i + 10] == NULL || ( (cmd[i + 10] == '.') && (cmd[i + 11] == 'e' || cmd[i + 11] == 'E') && (cmd[i + 12] == 'x' || cmd[i + 12] == 'X') && (cmd[i + 13] == 'e' || cmd[i + 13] == 'E'))))
                {
                    cout << "Недопустимая команда!\n";
                    goto lol;
                }
                // C:
                if ((cmd[i] == 'c' || cmd[i] == 'C') && cmd[i+1] == ':' && cmd[i+2] == '\\' )
                {
                    cout << "Недопустимая команда!\n";
                    goto lol;
                }
                //just enter
                if (cmd[0] == NULL)
                    goto lol;
            }
        system(cmd);
        
    }

    return 0;
}