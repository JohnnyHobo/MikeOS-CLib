#ifndef MOSCLIB_HAS_STDARG
#define MOSCLIB_HAS_STDARG

typedef char* va_list;

#define __align_size(type) ((sizeof(int) + sizeof(int) - 1) & -sizeof(int))
#define va_start(ap, n) { ap = (char*) &n + __align_size(n); }
#define va_arg(ap, type) (ap += __align_size(type), *(type*) (ap - __align_size(type)))
#define va_end(ap)

#endif
