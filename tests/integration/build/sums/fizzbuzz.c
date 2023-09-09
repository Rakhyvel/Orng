/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1694154283266167218
#define ORNG_1694154283266167218

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    uint8_t* _0;
    int64_t _1;
} struct1;
typedef struct {
    uint64_t tag;
    union {
        struct1 _0;
        int64_t _1;
    };
} struct0;

/* Interned Strings */
char* string_0 = "\x66\x69\x7A\x7A\x62\x75\x7A\x7A";
char* string_1 = "\x62\x75\x7A\x7A";
char* string_2 = "\x66\x69\x7A\x7A";

/* Function forward definitions */
struct1 _2_main();
struct0 _4_fizzbuzz(int64_t _4_n);

/* Function definitions */
struct1 _2_main() {
    int64_t _2_t1;
    struct0 _2_t0;
    struct1 _2_$retval;
BB0:
    _2_t1 = 30;
    $lines[$line_idx++] = "tests/integration/sums/fizzbuzz.orng:3:14:\n    fizzbuzz(30).string\n            ^";
    _2_t0 = _4_fizzbuzz(_2_t1);
    $line_idx--;
    _2_$retval = (&_2_t0)->_0;
    return _2_$retval;
}

struct0 _4_fizzbuzz(int64_t _4_n) {
    int64_t _4_t1;
    int64_t _4_t2;
    int64_t _4_t3;
    uint8_t _4_t4;
    struct1 _4_t11;
    struct0 _4_t0;
    struct0 _4_$retval;
    int64_t _4_t5;
    int64_t _4_t6;
    uint8_t _4_t7;
    struct1 _4_t13;
    int64_t _4_t8;
    int64_t _4_t9;
    uint8_t _4_t10;
    struct1 _4_t15;
BB0:
    _4_t1 = 0;
    _4_t2 = 15;
    _4_t3 = _4_n % _4_t2;
    _4_t4 = _4_t1 == _4_t3;
    if (_4_t4) {
        goto BB4;
    } else {
        goto BB7;
    }
BB7:
    _4_t5 = 5;
    _4_t6 = _4_n % _4_t5;
    _4_t7 = _4_t1 == _4_t6;
    if (_4_t7) {
        goto BB10;
    } else {
        goto BB11;
    }
BB11:
    _4_t8 = 3;
    _4_t9 = _4_n % _4_t8;
    _4_t10 = _4_t1 == _4_t9;
    if (_4_t10) {
        goto BB14;
    } else {
        goto BB16;
    }
BB16:
    _4_t0 = (struct0) {.tag=1, ._1=_4_n};
    goto BB6;
BB6:
    _4_$retval = _4_t0;
    return _4_$retval;
BB14:
    _4_t15 = (struct1) {string_2, 5};
    _4_t0 = (struct0) {.tag=0, ._0=_4_t15};
    goto BB6;
BB10:
    _4_t13 = (struct1) {string_1, 5};
    _4_t0 = (struct0) {.tag=0, ._0=_4_t13};
    goto BB6;
BB4:
    _4_t11 = (struct1) {string_0, 9};
    _4_t0 = (struct0) {.tag=0, ._0=_4_t11};
    goto BB6;
}


int main()
{
  printf("%s",_2_main()._0);
  return 0;
}

#endif
