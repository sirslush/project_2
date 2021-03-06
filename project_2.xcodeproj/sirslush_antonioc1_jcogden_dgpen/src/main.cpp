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
    if (word.size()>1) {                //add connections to list
        conects.push_back(newconect);
        return conects;
    }
    
    else{                               //spearate between names
        newconect.setInputs(" ,");
        newconect.setOperation(word);
    }
    
    s >> word;
    newconect.setInputs(word);
    conects.push_back(newconect);
    return conects;
}

bool checkVarError(list<variable> varList, list<variable> computations, char toCheck){
    bool tf = false;
    int i;
    
    for(i = 0; i <= varList.size(); i++){
        if(toCheck == varList.getName(i)){
            tf = true;
        }}
    return tf;
}

list<variable> parseInputStringIOWire(string str, list<variable> varList){
    stringstream s(str);
    string word ="";
    s >> word;
    if (word == "input") {                              //input parse procedue
        variable input(word);
        //create inputs
        s >> word;
        //send size
        string size =word.substr(3,2);
        input.setSize(stoi(size));
        //scan in var names
        while (s >> word) {
            for (int i =0; i < word.size(); i++) {
                if (word.at(i)==',') {
                    word.pop_back();
                }
            }
            if (!input.getVarnames().empty()) {
                input.addVarName(" ,");
            }
            input.addVarName(word);
        }
        varList.push_back(input);
    }
    if (word == "output") {                             //output parse procedure
        variable output(word);
        //create outputs
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
    if (word == "wire") {                               //wire parse procedure
        variable wire(word);
        //create wires
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
    string myFilePath(argv[1]);                //assign input file name to myFilePath
    string oFilePath(argv[2]);                 //assign output file name to oFilePath
    list<variable> varList;
    list<conections> computations;
    //myinfile.open(argv[1]);                      //open specified input file
    myinfile.open(myFilePath);
    
    if (!myinfile)                               //print error if file name is not specified or not found
    {
        cout << "error opening input file\n";
        return 1;
    }
    
    while (std::getline(myinfile, str))         //scan all of input file
    {
        size_t found = str.find("=");
        if (found==string::npos) {
            varList = parseInputStringIOWire(str, varList);
        }
        else{
            computations = parseInputStringComp(str, computations);
        }
        for(int i = 0; i < str.length(); i++){
            char ch = str.at(i);
            if(ch < 0 || ch > 127){
                cout << "character outside of usable operators\n";
                return 1;
            }
        }
    }
    outputFunct(varList, computations, argv[2]);
    myinfile.close();
    myoutfile.close();
    return 0;
}
