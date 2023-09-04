/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1691899681449729182
#define ORNG_1691899681449729182

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
	int64_t _4;
} struct0;
typedef struct {
	int64_t* _0;
	int64_t _1;
} struct1;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _2_t3;
	int64_t _2_t4;
	int64_t _2_t5;
	struct0 _3_x;
	int64_t _2_t7;
	int64_t* _2_t13;
	int64_t _2_t14;
	struct1 _3_y;
	int64_t _2_t15;
	int64_t _2_t18;
	uint8_t _2_t19;
	int64_t _2_t20;
	int64_t _2_t21;
	int64_t _2_t25;
	uint8_t _2_t26;
	int64_t _2_t22;
	int64_t _2_$retval;
BB0:
	_2_t1 = 1;
	_2_t2 = 2;
	_2_t3 = 3;
	_2_t4 = 4;
	_2_t5 = 5;
	_3_x = (struct0) {_2_t1, _2_t2, _2_t3, _2_t4, _2_t5};
	_2_t7 = 0;
	_2_t13 = (((int64_t*)(&_3_x))+_2_t7);
	_2_t14 = 5;
	_3_y = (struct1) {_2_t13, _2_t14};
	_2_t15 = 2;
	_2_t18 = (&_3_y)->_1;
	_2_t19 = _2_t15 >= _2_t18;
	if (_2_t19) {
		goto BB7;
	} else {
		goto BB8;
	}
BB8:
	_2_t20 = 81;
	*(((int64_t*)((&_3_y)->_0))+_2_t15) = _2_t20;
	_2_t21 = 2;
	_2_t25 = (&_3_y)->_1;
	_2_t26 = _2_t21 >= _2_t25;
	if (_2_t26) {
		goto BB11;
	} else {
		goto BB12;
	}
BB12:
	_2_t22 = *(((int64_t*)((&_3_y)->_0))+_2_t21);
	_2_$retval = _2_t22;
	return _2_$retval;
BB11:
    $lines[$line_idx++] = "tests/integration/slices/mut-sliceof.orng:6:7:\n    y[2]\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
	goto BB12;
BB7:
    $lines[$line_idx++] = "tests/integration/slices/mut-sliceof.orng:5:7:\n    y[2] = 81\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
	goto BB8;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
