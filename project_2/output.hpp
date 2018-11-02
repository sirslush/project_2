//
//  output.hpp
//  project_2
//
//  Created by Alec Foster on Wednesday10/31.
//  Copyright © 2018 Alec Foster. All rights reserved.
//

#ifndef output_hpp
#define output_hpp

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <list>
#include <iostream>
#include <fstream>



using namespace std;

class variable { // test
public:
    variable(string name){type = name;}
    void setSize(int sizeIn){size = sizeIn;}
    void addVarName(string in){varNames.append(in);}
    string getType(){return type;}
    string getVarnames(){return varNames;}
    int getSize(){return size;}
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
    string getName(){return name;}
    string getOperation(){return operation;}
    string getInputs(){return inputs;}
private:
    string name = "";
    string operation = "";
    string inputs = "";
    
};
void makeWireOutputs(list<variable> list, ofstream &os);
void makeOutputsOutputs(list<variable> listTemp, ofstream &os);
void makeInputsOutputs(list<variable> listTemp, ofstream &os);
list<variable> makeListofVar(list<variable> list, string type);
int outputFunct(list<variable> varList, list<conections> computations);
list<int> getSizes(list<variable> varList);
void makeModules(list<conections> computations, ofstream &os);

#endif /* output_hpp */
