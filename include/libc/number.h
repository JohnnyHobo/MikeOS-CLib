#ifndef MOSCLIB_HAS_NUMBER
#define MOSCLIB_HAS_NUMBER

#define RAND_MAX	(32768u)

typedef struct {
	int quot;
	int rem;
} div_t;

int rand();
int abs(int n);
struct div_v div(int numer, int denom);


#endif
