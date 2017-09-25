Assignment done as part of course IS F311 Computer Graphics
BITS PILANI, HYDERABAD Campus

Group Members:

Neetu				:	2015A7PS0079H
Abhishek Savani		:	2015A7PS0087H

#Objective:

The assignment objective is to read and implement the following text on natural object drawing.

Title: Plants, fractals, and formal languages,

Author: Alvy Ray Smith, Computer Graphics Project, Computer Division, Lucasfilm Ltd.
Proceeding: SIGGRAPH '84 Proceedings of the 11th annual conference on Computer graphics
and interactive techniques

#More info on the below links:

a) http://algorithmicbotany.org/papers/
b) http://algorithmicbotany.org/papers/WebApps/LSystems/LSys.html
c) “Graphical application of L-systems” by Przemyslaw Prusinkiewicz.

# lindenmayer-systems
An implementation of L-systems using opengl in c++.

#Build the code:

To run the lsystem code:

  -type in the command line:

    make
    
   -to run:
   
    ./lsystem

To run the draw_line code:
  
  -type in the command line:
    
    g++ -g draw_line.cpp draw_line.h -o line -lGL -lGLU -lglut
    
  - to run:
  
    ./line
    
To run the draw_circle code:

  - type in the command line:
    
     g++ -g draw_circle.cpp  -o circle -lGL -lGLU -lglut
   
  - to run:
    
     ./circle
    

 
