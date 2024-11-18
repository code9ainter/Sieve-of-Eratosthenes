#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int limit) {
	//creating vector and initializing all to true
    vector<bool> isPrime(limit + 1, true);
    // 0 and 1 are not prime numbers
    isPrime[0] = isPrime[1] = false;
    
    //Sieve algorithm
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            // Mark multiples of i as non-prime
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    //Print all prime numbers
    cout << "Prime numbers up to " << limit << " are: ";
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int limit;
    
    cout << "Enter the limit to find prime numbers: ";
    cin >> limit;
    
    sieveOfEratosthenes(limit);
    
    return 0;
}
