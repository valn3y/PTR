#ifndef DSTRING
#define DSTRING

#include <stdlib.h>

struct dstring;
typedef struct dstring* dstring;

// Create variadic prototypes
#define $(s) dstring_base(s)
#define N$(c) dstring_new(c)
#define L$(s) dstring_len(s)
#define C$(s1,s2) dstring_concat(s1,s2)
#define Ni$(i) dstring_newInt(i)
#define Nf$(f, lf) dstring_newFloat(f, lf)
#define Nd$(d, ld) dstring_newFloat(d, ld)
//#define MC$(s, ...) dstring_multiconcat(s, ...)

dstring dstring_new(const char * cstr);
char* dstring_base(dstring s);
void dstring_free(dstring s);
size_t dstring_len(dstring s);
dstring dstring_concat(const dstring s1, const dstring s2);
dstring dstring_multiconcat(const dstring s1, ...);
dstring dstring_newInt(int i);
dstring dstring_newFloat(float f, int lf);
dstring dstring_newDouble(double d, int ld);
    
#endif