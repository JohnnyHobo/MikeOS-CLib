#ifndef MOSCLIB_HAS_BOOLEAN
#define MOSCLIB_HAS_BOOLEAN

typedef enum {
	_Bool_is_int = -1,
	false = 0,
	true = 1
} _Bool;

#define bool _Bool

#define false 0
#define true 1

#define __bool_true_false_are_defined 1

#endif
