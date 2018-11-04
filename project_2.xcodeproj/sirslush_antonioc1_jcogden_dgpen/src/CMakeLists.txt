# Author: Alec Foster, Antonio Cervantes, Colter Ogden
# NetID: sirslush, antonioc1, jcogden
# Date: 11/4/2018
# Project 2

# Check if windows file 

	if(MSVC)

# Sets the compilation flags to report warnings through Level 4.

		set( CMAKE_CXX_FLAGS "-W4" )
    		set(CMAKE_DEBUG_POSTFIX "d")
    		add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    		add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
	else()
# debug information for all other OSs

   		add_definitions(-Wall -g)
    		link_libraries(m)
	endif()

file( GLOB SRCS *.cpp *.h )

add_executable( dgpen ${SRCS} )
