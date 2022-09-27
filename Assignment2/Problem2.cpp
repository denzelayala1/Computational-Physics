#include "LorentzVector.h"

int main(){

    LorentzVector<double> v1(1,0,0,1);
    LorentzVector<double> v2(1,0,0,-1);

    v1.print();
    v2.print();

    LorentzVector<double> v3(v1+v2);
    v3.print();
    std::cout << "v1 invariant mass = " << v1.mass() <<
                 "\nv2 invariant mass = " << v2.mass() <<
                 "\nv3 invariant mass = " << v3.mass() << std::endl;
}