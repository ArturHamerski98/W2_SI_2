#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

string input;
string onp;
vector < string > stack;

const int MAX_S = 100;

int checkCharacter(char c) {

    if (c == '+')
        return 1;
    else if (c == '-')
        return 1;
    else if (c == '*')
        return 2;
    else if (c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else if (c == '(')
        return 4;
    else if (c == ')')
        return 5;
    else
        return 0;
}

void oblicz(string onp) {
    string temp_string;
    for (int i = 0; i < onp.length(); i++) {
        temp_string = "";
        temp_string = onp[i];
        if (checkCharacter(onp[i]) == 0)
            stack.push_back(temp_string);
        else {
            double temp1, temp2;

            if (temp_string == "+") {
                temp1 = stof(stack.back());
                stack.pop_back();
                temp2 = stof(stack.back());
                stack.pop_back();
                stack.push_back(to_string(temp1 + temp2));

            }
            if (temp_string == "-") {
                temp1 = stof(stack.back());
                stack.pop_back();
                temp2 = stof(stack.back());
                stack.pop_back();
                stack.push_back(to_string(temp2 - temp1));

            }
            if (temp_string == "*") {
                temp1 = stof(stack.back());
                stack.pop_back();
                temp2 = stof(stack.back());
                stack.pop_back();
                stack.push_back(to_string(temp1 * temp2));

            }
            if (temp_string == "/") {
                temp1 = stof(stack.back());
                stack.pop_back();
                temp2 = stof(stack.back());
                stack.pop_back();
                stack.push_back(to_string(temp2 / temp1));

            }

        }
        for (int i = 0; i < stack.size(); i++) {
            cout << stack[i] << "|";
        }
        cout << "-----";

    }

}

int main() {

    cin >> input;

    string temp_string = "";
    for (int i = 0; i < input.length(); i++) {
        temp_string = "";
        if (checkCharacter(input[i]) == 0)
            onp.append(input, i, 1);
        else if (checkCharacter(input[i]) == 1) {
            temp_string = input[i];
            if ((stack.empty() == 1) || (checkCharacter(stack.back()[0]) == 4))
                stack.push_back(temp_string);
            else if (checkCharacter(stack.back()[0]) <= 1)
                stack.push_back(temp_string);
            else if (checkCharacter(stack.back()[0]) > 1) {
                onp.append(stack.back());
                stack.pop_back();
                stack.push_back(temp_string);

            }

        }
        else if (checkCharacter(input[i]) == 2) {
            temp_string = input[i];
            if (stack.empty() == 1)
                stack.push_back(temp_string);
            else if (checkCharacter(stack.back()[0]) <= 2)
                stack.push_back(temp_string);
            else if (checkCharacter(stack.back()[0]) > 2) {
                onp.append(stack.back());
                stack.pop_back();
                stack.push_back(temp_string);

            }
        }
        else if (checkCharacter(input[i]) == 4) {
            temp_string = input[i];

            stack.push_back(temp_string);

        }
        else if (checkCharacter(input[i]) == 5) {

            int temp_int;
            while (true) {
                temp_int = checkCharacter(stack.back()[0]);
                cout << stack.back()[0];

                if (temp_int == 4) {

                    stack.pop_back();
                    break;

                }
                else {
                    onp.append(stack.back());
                    stack.pop_back();
                }

            }

        }
    }

    while (stack.empty() == 0) {
        onp.append(stack.back());
        stack.pop_back();
    }
    cout << "\n" << onp << "\n";
    for (int i = 0; i < stack.size(); i++) {
        cout << stack[i];
    }
    //cout << stack.size();
    oblicz(onp);

    return 0;
}