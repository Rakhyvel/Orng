/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1693187140460137545
#define ORNG_1693187140460137545

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
} struct0;
typedef struct {
	int64_t* _0;
	int64_t _1;
} struct1;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
int64_t _4_f();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _2_t3;
	int64_t _2_t4;
	struct0 _3_x;
	int64_t _2_t6;
	int64_t* _2_t12;
	int64_t _2_t13;
	struct1 _3_y;
	int64_t _2_t14;
	int64_t _2_t15;
	uint8_t _2_t16;
	int64_t _2_t17;
	int64_t* _2_t18;
	int64_t* _2_t19;
	struct1 _3_z;
	int64_t _2_t21;
	int64_t _2_t25;
	uint8_t _2_t26;
	int64_t _2_t22;
	int64_t _2_$retval;
BB0:
	_2_t1 = 0;
	_2_t2 = 0;
	_2_t3 = 0;
	_2_t4 = 0;
	_3_x = (struct0) {_2_t1, _2_t2, _2_t3, _2_t4};
	_2_t6 = 0;
	_2_t12 = (((int64_t*)(&_3_x))+_2_t6);
	_2_t13 = 4;
	_3_y = (struct1) {_2_t12, _2_t13};
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
	_2_t14 = _4_f();
    $line_idx--;
	_2_t15 = 1;
	_2_t16 = _2_t14 > _2_t15;
	if (_2_t16) {
		goto BB5;
	} else {
		goto BB6;
	}
BB6:
	_2_t17 = _2_t15 - _2_t14;
	_2_t18 = (&_3_y)->_0;
	_2_t19 = _2_t18 + _2_t14;
	_3_z = (struct1) {_2_t19, _2_t17};
	_2_t21 = 0;
	_2_t25 = (&_3_z)->_1;
	_2_t26 = _2_t21 >= _2_t25;
	if (_2_t26) {
		goto BB9;
	} else {
		goto BB10;
	}
BB10:
	_2_t22 = *(((int64_t*)((&_3_z)->_0))+_2_t21);
	_2_$retval = _2_t22;
	return _2_$retval;
BB9:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:6:7:\n    z[0]\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
	goto BB10;
BB5:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    fprintf(stderr, "panic: subslice lower bound is greater than upper bound\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
	goto BB6;
}

int64_t _4_f() {
	int64_t _4_$retval;
BB0:
	_4_$retval = 2;
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
