#include <cassert>
#include <utility>
#include <iostream>

#include "rabin_miller.hpp"
#include "lucas_test.hpp"

// rosettacode.org/wiki/Jacobi_symbol

int jacobiSymbol(int n, int k) {
    assert(k > 0 && k % 2 == 1);
    n %= k;
    int t = 1;
    while (n != 0) {
        while (n % 2 == 0) {
            n /= 2;
            int r = k % 8;
            if (r == 3 || r == 5)
                t = -t;
        }
        std::swap(n, k);
        if (n % 4 == 3 && k % 4 == 3)
            t = -t;
        n %= k;
    }
    return k == 1 ? t : 0;

}

int D_chooser(int candidate) {
    int D = 5;
    while ( jacobiSymbol(D, candidate) != -1 ){
        if (D > 0 ) {
            D +=2;
        }else {
            D = -2;
        }
        D *= -1;
    }
    return D;
}

bool baillieTest(unsigned long num){
        // Check divisibility by a short list of primes less than 50
    auto candidate = num;
    auto knownPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    for(auto knownPrime: knownPrimes ){
        if(candidate == knownPrime){
            //std::cout << "Prime\n";
            return 1;
        }
        else if (candidate % knownPrime == 0){
            //std::cout << "Not Prime %" << knownPrime <<"\n" ;
            return 0;
        }
    }
    // Now perform the Miller-Rabin primality test base 2
    if ( !isPrimeRM(candidate, 2) ) {
        //std::cout << "Not Prime RM\n";
        return 0;
    }

    if ( !lucasTest(candidate) ){
        //std::cout << "Not Prime lucas\n";
        return 0;
    }
    //std::cout << "Prime\n";
    return 1;
}