//
//  output.cpp
//  project_2
//
//  Created by Alec Foster on Wednesday10/31.
//  Copyright © 2018 Alec Foster. All rights reserved.
//

#include "output.hpp"
#include <iostream>


int outputFunct(){
    ofstream myoutfile;
    myoutfile.open ("Ciruit1.txt");
    myoutfile << "`timescale 1ns / 1ps\n\n\n";
    
    myoutfile << "module circuit1(inputs/outputs);\n";
    myoutfile << "\tparameter Int(sizes);\n\n";
    myoutfile << "\tinput [Int(size)-1:0] (inputs);\n";
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

