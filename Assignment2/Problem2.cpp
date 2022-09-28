#include "LorentzVector.h"

int main(){

    LorentzVector<double> v1(1,0,0,1);
    LorentzVector<double> v2(1,0,0,-1);
    LorentzVector<double> v3(v1+v2);


    std::cout << "Lorentz Vector v1 = "; 
        v1.print() ;
    std::cout << "Lorentz Vector v2 = " ;
        v2.print();
    std::cout << "Lorentz Vector v3 = ";
        v3.print();


    std::cout << "v1 invariant mass = " << v1.mass() <<
                 "\nv2 invariant mass = " << v2.mass() <<
                 "\nv3 invariant mass = " << v3.mass() << std::endl;
}