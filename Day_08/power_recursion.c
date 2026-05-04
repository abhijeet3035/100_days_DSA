// Day 8: Compute Power Using Recursion
#include <stdio.h>

long long power(int base, int exp) {
    if (exp == 0) return 1;
    if (exp < 0) return 0; // For simplicity, handle only non-negative exponents
    return base * power(base, exp - 1);
}

int main() {
    int base, exp;

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exp);

    long long result = power(base, exp);
    printf("%d ^ %d = %lld\n", base, exp, result);

    return 0;
}
