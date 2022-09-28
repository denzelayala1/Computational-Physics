#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Line.h"
#include <typeinfo>


// Pass a pointer to a vector of points to a function to print them all
void print_all_lines( std::vector<Line> &vec ) {

  std::cout << "Lines made from Points are:\n" << std::endl;
  for ( unsigned int i = 0; i < vec.size(); ++i ) {
    std::printf("Line %u: \t",i+1);
    vec[i].print();
  }
}

void point_populate(std::ifstream &inFile, std::vector<Point> &p_vector ){
     bool valid = true;    
     std::cout << "You input Points:" << std::endl;

    while( valid ) {
        Point p1;
        valid = p1.input( inFile ) ;
        if ( not valid ) 
        break;
        std::cout << "Point: " ;
        p1.print();
        p_vector.push_back( p1 );
    }
}

void line_populate(std::vector<Line> &l_vector, std::vector<Point> &p_vector ){

    for ( uint32_t i = 0; i < p_vector.size(); ++i ) {
      for(uint32_t j = i+1; j < p_vector.size(); ++j){

        Line holder(p_vector[i], p_vector[j]);
        l_vector.push_back(holder);
      }
    }
}


int main(int argc, char ** argv) {

  //Create vectors
  std::ifstream inputfile(argv[1]);
  std::vector<Point> p_vector;  
  std::vector<Line> l_vector;



  // Populate vectors made 
  point_populate(inputfile, p_vector);
  line_populate(l_vector, p_vector);

  //Output lines
  std::cout << "---------------------------------\n";
  print_all_lines(l_vector);


  //Sort the vectors
  std::sort(l_vector.begin(), l_vector.end(), [](const Line& lhs,const Line& rhs){
    return lhs.m() > rhs.m();
  });  

  //Output sorted lines
  std::cout << "---------------------------------\nThe sorted lines are:\n";
  print_all_lines(l_vector);
  return 0;
}
