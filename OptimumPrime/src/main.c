
#include "OptimumPrime.h"

static inline void PrintInteger(mpz_t *one, mpz_t *n) {
    /** Don't print ones. */
    if (!mpz_cmp(*one,*n)) { return; }

    mpz_out_str(stdout, 10, *n); printf(" ");
}

static inline void PrintIntegerLabel(const char *label, mpz_t *n) {
    printf("%s: ", label); mpz_out_str(stdout, 10, *n); printf("\n");
}


int main(int argc, char *argv[])
{
    if (argc == 1) { return EXIT_SUCCESS; }

    mpz_t a;
    mpz_t b;
    mpz_t o;
    mpz_t s;

    mpz_init(a);
    mpz_init(b);
    mpz_init(o);
    mpz_init(s);

    mpz_set_str(a, argv[1], 10);
    mpz_set_str(b, "2", 10);
    mpz_set_str(o, "1", 10);

    /** Only check up to the square root of the number. */
    mpz_root(s, a, 2);

    do {
        while (mpz_divisible_p(a, b)) {
            mpz_tdiv_q(a, a, b);
            
            PrintInteger(&o, &b);
        }

        mpz_add(b, b, o);
    } while (!mpz_cmp(s, b));

    PrintInteger(&o, &a);
    
    printf("\n");

    return EXIT_SUCCESS;
}
