/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1693187126068324973
#define ORNG_1693187126068324973

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
} struct0;
typedef struct {
	int64_t* _0;
	int64_t _1;
} struct1;
typedef struct {
	struct1 _0;
	struct1 _1;
	struct1 _2;
} struct2;
typedef struct {
	struct1* _0;
	int64_t _1;
} struct3;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _2_t3;
	struct0 _3_x;
	int64_t _2_t6;
	int64_t* _2_t12;
	int64_t _2_t13;
	struct1 _2_t5;
	int64_t _2_t15;
	int64_t* _2_t21;
	int64_t _2_t22;
	struct1 _2_t14;
	int64_t _2_t24;
	int64_t* _2_t30;
	int64_t _2_t31;
	struct1 _2_t23;
	struct2 _3_y;
	int64_t _2_t33;
	struct1* _2_t39;
	int64_t _2_t40;
	struct3 _3_z;
	int64_t _2_t41;
	int64_t _2_t45;
	uint8_t _2_t46;
	struct1 _2_t42;
	int64_t _2_t47;
	int64_t _2_t50;
	uint8_t _2_t51;
	int64_t _2_t52;
	int64_t _2_t53;
	int64_t _2_t57;
	uint8_t _2_t58;
	struct1 _2_t54;
	int64_t _2_t59;
	int64_t _2_t63;
	uint8_t _2_t64;
	int64_t _2_t60;
	int64_t _2_$retval;
BB0:
	_2_t1 = 1;
	_2_t2 = 2;
	_2_t3 = 3;
	_3_x = (struct0) {_2_t1, _2_t2, _2_t3};
	_2_t6 = 0;
	_2_t12 = (((int64_t*)(&_3_x))+_2_t6);
	_2_t13 = 3;
	_2_t5 = (struct1) {_2_t12, _2_t13};
	_2_t15 = 0;
	_2_t21 = (((int64_t*)(&_3_x))+_2_t15);
	_2_t22 = 3;
	_2_t14 = (struct1) {_2_t21, _2_t22};
	_2_t24 = 0;
	_2_t30 = (((int64_t*)(&_3_x))+_2_t24);
	_2_t31 = 3;
	_2_t23 = (struct1) {_2_t30, _2_t31};
	_3_y = (struct2) {_2_t5, _2_t14, _2_t23};
	_2_t33 = 0;
	_2_t39 = (((struct1*)(&_3_y))+_2_t33);
	_2_t40 = 3;
	_3_z = (struct3) {_2_t39, _2_t40};
	_2_t41 = 1;
	_2_t45 = (&_3_z)->_1;
	_2_t46 = _2_t41 >= _2_t45;
	if (_2_t46) {
		goto BB19;
	} else {
		goto BB20;
	}
BB20:
	_2_t42 = *(((struct1*)((&_3_z)->_0))+_2_t41);
	_2_t47 = 2;
	_2_t50 = ((((struct1*)((&_3_z)->_0))+_2_t41))->_1;
	_2_t51 = _2_t47 >= _2_t50;
	if (_2_t51) {
		goto BB23;
	} else {
		goto BB24;
	}
BB24:
	_2_t52 = 82;
	*(((int64_t*)((&_2_t42)->_0))+_2_t47) = _2_t52;
	_2_t53 = 1;
	_2_t57 = (&_3_z)->_1;
	_2_t58 = _2_t53 >= _2_t57;
	if (_2_t58) {
		goto BB27;
	} else {
		goto BB28;
	}
BB28:
	_2_t54 = *(((struct1*)((&_3_z)->_0))+_2_t53);
	_2_t59 = 2;
	_2_t63 = ((((struct1*)((&_3_z)->_0))+_2_t53))->_1;
	_2_t64 = _2_t59 >= _2_t63;
	if (_2_t64) {
		goto BB31;
	} else {
		goto BB32;
	}
BB32:
	_2_t60 = *(((int64_t*)((&_2_t54)->_0))+_2_t59);
	_2_$retval = _2_t60;
	return _2_$retval;
BB31:
    $lines[$line_idx++] = "tests/integration/slices/multi-dim.orng:7:10:\n    z[1][2]\n          ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
	goto BB32;
BB27:
    $lines[$line_idx++] = "tests/integration/slices/multi-dim.orng:7:7:\n    z[1][2]\n       ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
	goto BB28;
BB23:
    $lines[$line_idx++] = "tests/integration/slices/multi-dim.orng:6:10:\n    z[1][2] = 82\n          ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
	goto BB24;
BB19:
    $lines[$line_idx++] = "tests/integration/slices/multi-dim.orng:6:7:\n    z[1][2] = 82\n       ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
	goto BB20;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
