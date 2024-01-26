
#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int is_good_prime(int i, int primes[], int n) {
        if (primes[i] * primes[i] <= primes[i-1] * primes[i + 1]) {
            return 0;
        }
    return 1;
}

int is_circular_prime(int prime) {
    int num = prime;
    int count = 0;

    while (num > 0) {
        count++;
        num /= 10;
    }

    int powTen = pow(10, count - 1);
    num = prime;

    for (int i = 0; i < count - 1; i++) {
        int firstDigit = num / powTen;
        num = (num % powTen) * 10 + firstDigit;

        if (!is_prime(num)) {
            return 0;
        }
    }

    return 1;
}

void write_to_file(char *filename, int primes[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", primes[i]);
    }

    fclose(file);
}

int main() {
    int primes[1000];
    int primeCount = 0;

    for (int num = 2; num <= 1000; num++) {
        if (is_prime(num)) {
            primes[primeCount++] = num;
        }
    }
    printf("Primes: ");
    for (int i = 0; i < primeCount; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    int goodPrimes[20];
    int goodPrimeCount = 0;

    for (int i = 1; i < primeCount; i++) {
        if (is_good_prime(i, primes, primeCount)) {
            goodPrimes[goodPrimeCount++] = primes[i];
        }
    }
    

    int circularPrimes[20];
    int circularPrimeCount = 0;

    for (int i = 0; i < goodPrimeCount; i++) {
        if (is_circular_prime(goodPrimes[i])) {
            circularPrimes[circularPrimeCount++] = goodPrimes[i];
        }
    }
    
    printf("Good Primes: ");
    for (int i = 0; i < goodPrimeCount; i++) {
        printf("%d ", goodPrimes[i]);
    }
    printf("\n");

    // Print circularPrimes
    printf("Circular Primes: ");
    for (int i = 0; i < circularPrimeCount; i++) {
        printf("%d ", circularPrimes[i]);
    }
    printf("\n");
    write_to_file("gprime.txt", goodPrimes, goodPrimeCount);
    write_to_file("cgprime.txt", circularPrimes, circularPrimeCount);

    return 0;
}
