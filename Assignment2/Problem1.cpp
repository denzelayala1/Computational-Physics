#include <iostream>
#include <stdlib.h>

using namespace std;


unsigned int factorial(unsigned int x);

int main(int argc, char** argv){

    if(argc < 2){
        printf("WARNING!!!!\tThere were no inputs.\tWARNING!!!!\nPlease rerun with at least one input value.\n");
    }

    for(int i = 1; i < argc; ++i){
        
        printf("\n%s! = %d\n", argv[i], factorial(atol(argv[i])) );
    }

    return 0;
}

unsigned int factorial(unsigned int x){
    if(x >= 20){
        printf("WARNING!!!!\nThe factorial of %d is too large.\nPlease input a smaller number\n" , x);
        exit(0);
    } else if(x == 0){
        printf("WARNING!!!!\nThe input: %d may have been something other than an integer\n", x);
        return 1;
    } else {
        unsigned int val = x;
        int i = x;
        while(i>1){
            --i;
            val *=i;
        }
        return val;
    }
}