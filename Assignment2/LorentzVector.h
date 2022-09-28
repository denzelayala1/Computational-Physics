#pragma once
#include <iostream>
#include <stdlib.h>
#include <math.h>


template<class F> 
class LorentzVector{
    private:
    //private fields
    F t_m;
    F x_m;
    F y_m;
    F z_m;
   

    public:

    // Constructors for class
    LorentzVector(): t_m(0),
                     x_m(0), 
                     y_m(0),
                     z_m(0) {}

    LorentzVector(F it, F ix, F iy, F iz) : t_m(it),
                                            x_m(ix),
                                            y_m(iy),
                                            z_m(iz) {}

    LorentzVector(const LorentzVector& inVector) : t_m(inVector.t_m),
                                                   x_m(inVector.x_m),
                                                   y_m(inVector.y_m),
                                                   z_m(inVector.z_m) {}

    // Destructor
    ~LorentzVector(){};

    //methods

    //getters
    F t() const {return t_m;}
    F x() const {return x_m;}
    F y() const {return y_m;}
    F z() const {return z_m;}


    //setters
    void set_t(F it){t_m = it;}
    void set_x(F ix){x_m = ix;}
    void set_y(F iy){y_m = iy;}
    void set_z(F iz){z_m = iz;}



    // Computes invariant mass
    F mass() const{
        F m = sqrt(this->t_m * this->t_m
                    - this->x_m * this->x_m
                    - this->y_m * this->y_m
                    - this->z_m * this->z_m );
        return m;
    }
    
    void print(){
        std::cout << "(" <<t_m << ", " <<
                            x_m << ", " <<
                            y_m << ", " <<
                            z_m << ")" << std::endl ; 
    }


    //Operators

    LorentzVector operator+(LorentzVector const & right) const{
        LorentzVector retVector(t_m + right.t_m,
                                x_m + right.x_m,
                                y_m + right.y_m, 
                                z_m + right.z_m);
        return retVector;
    }
       

};

typedef LorentzVector<double> DoubleLorentzVector;