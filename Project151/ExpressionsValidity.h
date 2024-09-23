#include <string>
#include <stack>
#include <cctype> 
using namespace std;
bool isValidExpression(const string& expression) {
    stack<char> s;
    char lastChar = ' '; 

    for (char ch : expression) {
  
        if (isspace(ch)) {
            continue;
        }
    if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') &&
            (lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/')) {
            return false; 
        }

        if (lastChar != '(' && lastChar != ')' && !(lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/')) {
            lastChar = ch;
        }

        if (ch == '(') {
            s.push(ch);
        }
     
        else if (ch == ')') {
            if (s.empty()) {
                return false;  
            }
            s.pop(); 
        }
    }

    return s.empty();
}
