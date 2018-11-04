//
//  output.cpp
//  project_2
//
//  Created by Alec Foster on Wednesday10/31.
//  Copyright © 2018 Alec Foster. All rights reserved.
//

#include "output.hpp"
#include <iostream>
#include <algorithm>

list<variable> makeListofVar(list<variable> listin, string type){
    list<variable> returTempList;
    for (list<variable>::iterator it = listin.begin(); it != listin.end(); ++it) {
        if (it->getType() == type) {
            returTempList.push_back(*it);
        }
    }
    return returTempList;
}

void makeWireOutputs(list<variable> listTemp, ofstream &os){
    for (list<variable>::iterator it = listTemp.begin(); it != listTemp.end(); ++it){
        os << "\twire [Int"<<it->getSize() <<"-1:0] "<<it->getVarnames() << ";\n";
    }
    
}
void makeOutputsOutputs(list<variable> listTemp, ofstream &os){
    for (list<variable>::iterator it = listTemp.begin(); it != listTemp.end(); ++it){
        os << "\toutput [Int"<<it->getSize() <<"-1:0] "<<it->getVarnames() << ";\n";
    }
    
}
void makeInputOutputs(list<variable> listTemp, ofstream &os){
    for (list<variable>::iterator it = listTemp.begin(); it != listTemp.end(); ++it){
        os << "\tinput [Int"<<it->getSize() <<"-1:0] "<<it->getVarnames() << ";\n";
    }
    
}

list<int> getSizes(list<variable> varList){
    list<int> sizes;
    for (list<variable>::iterator it = varList.begin(); it != varList.end(); ++it) {
        if (!(find(sizes.begin(), sizes.end(), it->getSize()) != sizes.end())) {
            sizes.push_back(it->getSize());
        }
    }
    return sizes;
}

void makeParameters(list<variable> varList, ofstream &os){
    list<int> sizes = getSizes(varList);
    for (list<int>::iterator it = sizes.begin(); it != sizes.end(); it++) {
        os << "\n\tparameter Int";
        os << *it << " = " << *it << ";\n";
    }
}
void makeModules(list<conections> computations, ofstream &os){
    int nums[10] = {0}; // add 0, sub 1, compareq 2, SHR 3, ...
    for (list<conections>::iterator it = computations.begin(); it != computations.end(); ++it) { os << "\t";
        if (it->getOperation() == "=+") {
            os << "ADD #(.DATAWIFTH(Int(SIZE fix))) add" << nums[0] << "(" << it->getName() << " ," << it->getInputs() << ");\n\n";
            nums[0]++;
        }
        else if (it->getOperation() == "=-"){
            os << "SUB #(.DATAWIFTH(Int(SIZE fix))) sub" << nums[1] << "(" << it->getName() << " ," << it->getInputs() << ");\n\n";
            nums[1]++;
        }
        else if (it->getOperation() == "==="){
            os << "COMP #(.DATAWIFTH(Int(SIZE fix))) comp" << nums[2] << "(" << it->getName() << " ," << it->getInputs() << ");\n\n";
            nums[2]++;
        }
        else if (it->getOperation() == "=<"){
            os << "COMP #(.DATAWIFTH(Int(SIZE fix))) comp" << nums[2] << "(" << it->getName() << " ," << it->getInputs() << ");\n\n";
            nums[2]++;
        }
        else if (it->getOperation() == "=>"){
            os << "COMP #(.DATAWIFTH(Int(SIZE fix))) comp" << nums[2] << "(" << it->getName() << " ," << it->getInputs() << ");\n\n";
            nums[2]++;
        }
        else if (it->getOperation() == "=<<"){
            os << "SHL #(.DATAWIFTH(Int(SIZE fix))) shl" << nums[3] << "(" << it->getName() << " ," << it->getInputs() << ");\n\n";
            nums[3]++;
        }
        else if (it->getOperation() == "=>>"){
            os << "SHR #(.DATAWIFTH(Int(SIZE fix))) shr" << nums[4] << "(" << it->getName() << " ," << it->getInputs() << ");\n\n";
            nums[4]++;
        }
        else if (it->getOperation() == "=?"){
            os << "MUX2x1 #(.DATAWIFTH(Int(SIZE fix))) mux2x1_" << nums[5] << "(" << it->getName() << " ," << it->getInputs() << ");\n\n";
            nums[5]++;
        }
        else if (it->getOperation() == "=*"){
            os << "MUL #(.DATAWIFTH(Int(SIZE fix))) mul" << nums[6] << "(" << it->getName() << " ," << it->getInputs() << ");\n\n";
            nums[6]++;
        }
        else if (it->getOperation() == "="){
            os << "REG #(.DATAWIFTH(Int(SIZE fix))) reg" << nums[7] << "(Clk, Rst, " << it->getName() << " ," << it->getInputs() << ");\n\n";
            nums[7]++;
        }
    }
}


int outputFunct(list<variable> varList, list<conections> computations, string oFile){ //check that this is done right, not sure
    ofstream myoutfile;
    list<variable> temp;
    list<variable> insandOuts;
    myoutfile.open (oFile);
    
    if (!myoutfile)                              //print error if file name is not specified or not found
    {
        cout << "error opening output file\n";
        return 1;
    }
    
    myoutfile << "`timescale 1ns / 1ps\n\n\n";
    
    myoutfile << "module circuit1(";
    temp = makeListofVar(varList, "input");
    insandOuts = temp;
    temp = makeListofVar(varList, "output");
    insandOuts.splice(insandOuts.end(), temp);
    for (list<variable>::iterator it = insandOuts.begin(); it != insandOuts.end(); it++) {
        myoutfile << it->getVarnames() << " ,";
    }
    myoutfile << "Clk, Rst);\n\n";
    
    //inputs
    makeParameters(varList, myoutfile);
//    list<int> sizes = getSizes(varList);
//    list<int>::iterator itSize = sizes.begin();
//    myoutfile << "\n\tparameter Int";
//    myoutfile << &itSize << " = " << &itSize << ";\n\n";
    
    myoutfile << "\n\tinput Clk, Rst;\n";
    temp = makeListofVar(varList, "input");
    makeInputOutputs(temp, myoutfile);

    //outputs
    temp = makeListofVar(varList, "output");
    makeOutputsOutputs(temp, myoutfile);

    //wires
    temp = makeListofVar(varList, "wire");
    makeWireOutputs(temp, myoutfile);
    
    myoutfile << "\n\n";
    // make modules
    makeModules(computations, myoutfile);
    
    myoutfile << "\n\nendmodule";
    


    myoutfile.close();
    return 1;
}

