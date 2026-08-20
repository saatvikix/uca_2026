#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

bool balancedParanthesis(string str) {

    unordered_map <char,char> paranthesis_map;
    paranthesis_map.insert({'[', ']'});
    paranthesis_map.insert({'(', ')'});
    paranthesis_map.insert({'{', '}'});

    stack<char> st;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '[' || str[i] == '(' || str[i] == '{') {
            st.push(str[i]);
        }
        else{

            if(st.empty()) {
                return false;
            }

            char top = st.top();
            st.pop();

            if( paranthesis_map[top] != str[i] ) {
                return false;
            }

        }
    }

    if(!st.empty()) return false;

    return true;


}

int main() {

    string test1 = "[()]{}{()()}";
    string test2 = "[()";

    cout<<balancedParanthesis(test1)<<endl;
    cout<<balancedParanthesis(test2)<<endl;
}