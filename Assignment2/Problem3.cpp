#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include"Line.h"


// Pass a pointer to a vector of points to a function to print them all
void print_all_lines( std::vector<Line> * vec ) {

  std::cout << "Lines made from Points are:" << std::endl;
  for ( unsigned int i = 0; i < vec->size(); ++i ) {
    (*vec)[i].print();
  }
}

void point_populate(std::ifstream &inFile, std::vector<Point> &p_vector ){
     bool valid = true;    
     std::cout << "You input:" << std::endl;

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

      l_vector.resize(p_vector.size());
     

    for ( unsigned int i = 0; i < p_vector.size(); ++i ) {

        
        l_vector.push_back
    }
}

void sort_lines(std::vector<Line> * vec){
    
        Line holder;
        int j;

    for ( unsigned int i = 1; i < vec->size(); ++i ) {

        j = i-1;
        holder =  Line((*vec)[i]);
        //holder.setIntercept( (*vec)[i].b() );
        //holder.setSlope( (*vec)[i].m() );

        while(j >= 0 && (*vec)[j].m() > (*vec)[i].m() ){
            (*vec)[j+1].setSlope( (*vec)[j].m() );
            j--;            
        }
        
        (*vec)[j+1] = Line( holder);
        
    }

}

int main(int argc, char ** argv) {

  std::ifstream inputfile( "points.txt");
  std::vector<Point> p_vector;  
  std::vector<Line> l_vector;



  // Now LOOP!
  point_populate(inputfile, p_vector);



  return 0;
}
