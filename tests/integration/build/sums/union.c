/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688791346313859981
#define ORNG_1688791346313859981

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	uint8_t* _0;
	int64_t _1;
} struct1;
typedef struct {
	uint64_t tag;
	union {
		int64_t _0;
		struct1 _1;
		int64_t _2;
		struct1 _3;
	};
} struct0;

/* Interned Strings */
char* string_0 = "\x4C\x6D\x61\x6F\x21";
char* string_1 = "\x6C\x6F\x6C";

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t6;
	struct0 _3_x;
	int64_t _2_t8;
	int64_t _2_$retval;
BB0:
	_2_t6 = 108;
	_3_x = (struct0) {.tag=2, ._2=_2_t6};
	_2_t8 = *&((&_3_x)->_2);
	_2_$retval = _2_t8;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
