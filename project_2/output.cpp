//
//  output.cpp
//  project_2
//
//  Created by Alec Foster on Wednesday10/31.
//  Copyright © 2018 Alec Foster. All rights reserved.
//

#include "output.hpp"
#include <iostream>


int outputFunct(list<variable> varList, list<conections> computations){
    ofstream myoutfile;
    
    myoutfile.open ("Ciruit1.txt");
    myoutfile << "`timescale 1ns / 1ps\n\n\n";
    
    myoutfile << "module circuit1(";
//    for (std::list<Student>::iterator it = data.begin(); it != data.end(); ++it){
//        std::cout << it->name;
//    }
    for (list<variable>::iterator it = varList.begin(); it != varList.end(); ++it) {
        myoutfile << it->getVarnames() << " ,";
    }
    myoutfile << ");\n";
    
    //inputs
    list<variable>::iterator it = varList.begin();

    myoutfile << "\n\tparameter Int";
    myoutfile << it->getSize() << ";\n\n";
    myoutfile << "\tinput [Int";
    myoutfile << it->getSize() << "-1:0] ";
    myoutfile << it->getVarnames() << ";\n";
    myoutfile << "\tinput Clk, Rst;\n";
    myoutfile << "\toutput [Int(size)-1:0] (output);\n";
    myoutfile << "\toutput [Int(size)-1:0] (output);\n";
    
    myoutfile << "\twire (wirename);\n";
    myoutfile << "\twire [Int(size)-1:0] (wire);\n";
    myoutfile << "\twire [Int(size)-1:0] (wire);\n";
    
    
    
    myoutfile << "\n\nendmodule";
    


    myoutfile.close();
    return 1;
}

