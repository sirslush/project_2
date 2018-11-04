1)	Alec Foster		sirslush
	Antonio Cervantes	antonioc1
	Colter Ogden		jcogden

2)	ECE474A

3)	Program takes the behavioral net list files provided and translates them into
	Verilog code to be run on Vivado, using the library from our previous assignment.
	
	main.cpp contains input parsing (classes and execution), as well as the call to 
	output parsing. It takes the behavioral netlist and divides the instructions into 
	arrays that can be handled by our output file.

	output.cpp contains output parsing, popping the different items from the
	input/output/wire/reg specifications created in main.cpp, and uses them with 
	an array of specified connectors also created in main.cpp. The file uses
	these instructions to print to the specified output file. 

4)	sirslush 	- all primary conception and code execution. (major project 
			programmer)
	
	antonioc1 	- 	
	
	jcogden		- code comments, connected files (readme/cmake etc), 
			fileIO arg adjustments, minor code changes
