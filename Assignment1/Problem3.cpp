#include <iostream>
#include <iomanip>

using namespace std;

// prints a formated Table Header
void header(){

    cout << left << setw(17) << "\nIteration" <<
                    setw(15) << "int" << 
                    setw(17) << "long int" << 
                    setw(23) << "unsigned long int" <<
                    "\n--------------------------------------------------------------------" << endl;
}

void fn_out(int count, int val, long long_val, unsigned long unsigned_val ){
         
        cout << left << setw(2) << "n= "   << setw(13) << count <<
                        setw(5) << "fn = " << setw(10) << val <<
                        setw(5) << "fn = " << setw(12) << long_val <<
                        setw(5) << "fn = " << setw(18) << unsigned_val <<
                        endl;

}

int main() {

    //Declaring Variables    
    int fn=2;
    long int long_fn=2;
    unsigned long int unsigned_fn= 2;

    header();

    // Series Calculation and Output
    for (int n=0 ; n <= 10; ++n) {
        
        //Outputs fn formating matching the header: iteration, int, long, unsigned long 
        fn_out(n, fn, long_fn, unsigned_fn);
        
        // calculating f_(n+1) using f_(n+1)= fn^2
        fn = fn * fn;
        long_fn = long_fn * long_fn;
        unsigned_fn = unsigned_fn * unsigned_fn;
    }

    cout << endl;
    return 0;
}

