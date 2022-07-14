// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5213414#overview
#include "bits/stdc++.h"
#include <sstream>
using namespace std;

string simplifyPath(string path){
    istringstream iss(path);
    vector<string> tokens;
    string token;
    while(getline(iss,token,'/')){
        if(token == "." or token == "")continue;
        tokens.push_back(token);
    }
    vector<string> stack;
    if(path[0] == '/'){
        // denotes that our path is an abs path
        stack.push_back("");
    }
    for(string token : tokens){
        if(token == ".."){
            if(stack.size() == 0 or stack[stack.size()-1] == ".."){
                stack.push_back("..");
            }else if(stack[stack.size()-1] != ""){
                stack.pop_back();
            }
        }else{
            stack.push_back(token);
        }
    }
    if(stack.size() ==  1 and stack[0] == "") return "/";
    ostringstream oss;
    for(auto token:stack){
        oss << token  << "/";
    }

    return oss.str();
}

int main(){
    string path = "/../x/y/.../z/././w/a///../../c/./";
    cout << simplifyPath(path);
    return 0;
}