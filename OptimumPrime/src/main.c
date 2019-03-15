
#include "OptimumPrime.h"

static inline void PrintInteger(mpz_t *one, mpz_t *n) {
    /** Don't print ones. */
    if (!mpz_cmp(*one,*n)) { return; }

    mpz_out_str(stdout, 10, *n); printf(" ");
}

static inline void PrintIntegerLabel(const char *label, mpz_t *n) {
    printf("%s: ", label); mpz_out_str(stdout, 10, *n); printf("\n");
}


int main()
{
    mpz_t a;
    mpz_t b;
    mpz_t o;
    mpz_t s;

    mpz_init(a);
    mpz_init(b);
    mpz_init(o);
    mpz_init(s);

    //mpz_set_str(a, "10000", 10);
    //mpz_set_str(a, "5432000", 10);
    //mpz_set_str(a, "858443", 10);
    //mpz_set_str(a, "1858443", 10);
    //mpz_set_str(a, "41858443", 10);
    //mpz_set_str(a, "341858443", 10);
    //mpz_set_str(a, "2341858443", 10);
    //mpz_set_str(a, "82341858443", 10);
    //mpz_set_str(a, "782341858443", 10);
    //mpz_set_str(a, "9782341858443", 10);
    //mpz_set_str(a, "49782341858443", 10);
    //mpz_set_str(a, "549782341858443", 10);
    mpz_set_str(a, "8549782341858443", 10);
    //mpz_set_str(a, "1000000000000000000000", 10);
    mpz_set_str(b, "2", 10);
    mpz_set_str(o, "1", 10);

    /** Only check up to the square root of the prime. */
    mpz_root(s, a, 2);

    PrintIntegerLabel("a", &a);
    PrintIntegerLabel("s", &s);

    printf("\n");

    while (mpz_cmp(a, o)) {
        if (!mpz_cmp(s,b)) {
            break;
        }

        if (mpz_divisible_p(a, b)) {
            do {
                mpz_tdiv_q(a, a, b);
            
                PrintInteger(&o, &b);
            } while (mpz_divisible_p(a, b));
        }

        mpz_add(b, b, o);
    }

    PrintInteger(&o, &a);

    printf("\n\nDone. \n");

    return EXIT_SUCCESS;
}
