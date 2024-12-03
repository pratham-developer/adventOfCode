#include <iostream>
#include <fstream>
#include<vector>
#include <string>
using namespace std;

int evaluate(string exp){ // func to evaluate the expression
    int firstIndexOfComma = exp.find_first_of(','); // finding first index of comma
    int lastIndexOfComma = exp.find_last_of(','); // finding second index of comma

    // Cases for invalid expressions
    // if(first<=0)->return 0
    // if(first!=last)->return 0
    // if(first>3) -> return 0 -> not a 3 digit number
    if(firstIndexOfComma<=0 || firstIndexOfComma!=lastIndexOfComma || firstIndexOfComma>3){
        return 0;
    }

    //finding n1 and n2
    int n1=0;
    int n2=0;
    int i;

    for(i=0;i<firstIndexOfComma;i++){ // iterate till first
        if(!isnumber(exp[i])){ //if not a number then invalid exp -> return 0
            return 0;
        }
        else{
            n1=(n1*10)+(exp[i]-'0'); //otherwise add to n1
        }
    }

    for(i=firstIndexOfComma+1;i<exp.size();i++){
        if(!isnumber(exp[i])){ //similarly for n2
            return 0;
        }
        else{
            n2=(n2*10)+(exp[i]-'0');
        }
    }

    return n1*n2; //finally add n1*n2 to the answer
}


int main(){
    //READING THE INPUT
    ifstream file("input.txt");
    if(!file.is_open()){
        cout<<"error opening the file"<<endl;
        return 1;
    }
    string temp;
    string inp=""; //INPUT STRING
    while(getline(file,temp)){
        inp+=temp+'\n';
    }

    int ans=0; //DECLARING ANSWER = 0
    string mul = "mul("; //STRING TO FIND
    vector<int> indices; //VECTOR TO STORE INDICES

    for(int i=0;i<inp.size();i++){
        if((inp.substr(i,mul.size())==mul)){
            indices.push_back(i); //IF ANY SUBSTRING == "mul(" -> push index to the vector
        }
    }

    for(int i: indices){ // FOR EACH INDEX
        int j=i+4; // setting j=i+4 because "mul(" has a length of 4 and we have to check after it
        string exp = ""; // declaring a string expression to hold what comes after "mul("
        while(j<inp.size() && j<i+11 && inp[j]!=')'){
            // j<len(inp) to prevent going after the end of the input string
            // j<i+11 to consider max size of expression before ')' can be 7 as -> 137,345 -> both 3 digit and a comma
            exp+=inp[j]; // adding characters to get the expression string
            j++;
        }
        if(inp[j]==')'){ // if the character of loop is a closing bracket then we add its value to the answer
            ans+=evaluate(exp); // evaluate function
            
        }
    }

    cout<<ans; //printing the answer
    return 0;
}