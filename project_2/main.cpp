//
//  main.cpp
//  project_2
//
//  Created by Alec Foster on Thursday10/25.
//  Copyright © 2018 Alec Foster. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <list>
#include "output.hpp"


using namespace std;

class variable { // test
public:
    variable(string name){type = name;}
    void setSize(int sizeIn){size = sizeIn;}
    void addVarName(string in){varNames.append(in);}
    string getType(){return type;}
private:
    string type = "";
    string varNames= "";
    int size = 0;
};

class conections {
public:
    void setVar(string namein){name = namein;}
    void setOperation(string operIn){operation.append(operIn);}
    void setInputs(string inp){inputs.append(inp);}
private:
    string name = "";
    string operation = "";
    string inputs = "";

};


void createNewVar(variable){
    
}
list<conections> parseInputStringComp(string str, list<conections> conects){
    stringstream s(str);
    string word ="";
    conections newconect;
    s >> word;
    newconect.setVar(word);
    s >> word;
    newconect.setOperation(word);
    s >> word;
    newconect.setInputs(word);
    s >> word;
    newconect.setOperation(word);
    s >> word;
    newconect.setInputs(word);
    conects.push_back(newconect);
    return conects;
}

list<variable> parseInputStringIOWire(string str, list<variable> varList){
    stringstream s(str);
    string word ="";
    s >> word;
    if (word == "input") {
        variable input(word);
        //create inputs
        s >> word;
        //send size
        string size =word.substr(3,2);
        input.setSize(stoi(size));
        //scan in var names
        while (s >> word) {
            input.addVarName(word);
        }
        varList.push_back(input);
    }
    if (word == "output") {
        variable output(word);
        //create inputs
        s >> word;
        //send size
        string size =word.substr(3,2);
        output.setSize(stoi(size));
        //scan in var names
        while (s >> word) {
            output.addVarName(word);
        }
        varList.push_back(output);

    }
    if (word == "wire") {
        variable wire(word);
        //create inputs
        s >> word;
        //send size
        string size =word.substr(3,2);
        wire.setSize(stoi(size));
        //scan in var names
        while (s >> word) {
            wire.addVarName(word);
        }
        varList.push_back(wire);
    }
    return varList;
}

int main(int argc, const char * argv[]) {
    ofstream myoutfile;
    ifstream myinfile;
    string str;
    string myFilePath = "474a_circuit1.txt";
    list<variable> varList;
    list<conections> computations;

    myinfile.open(myFilePath);
    
    if (!myinfile)
    {
        cout << "error opening input file\n";
        return 1;
    }
    
    while (std::getline(myinfile, str))
    {
        size_t found = str.find("=");
        if (found==string::npos) {
            varList = parseInputStringIOWire(str,varList);
        }
        else{
            computations = parseInputStringComp(str, computations);
        }
    }
    outputFunct();
    myinfile.close();
    myoutfile.close();
    return 0;
}
