/* Code generated using the Orng compiler https://ornglang.org */
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
    struct0 _2_t0;
    struct1 _2_$retval;
    $lines[$line_idx++] = "tests/integration/sums/fizzbuzz.orng:3:14:\n    fizzbuzz(30).string\n            ^";
    _2_t0 = _4_fizzbuzz(30);
    $line_idx--;
    _2_$retval = (&_2_t0)->_0;
    return _2_$retval;
}

struct0 _4_fizzbuzz(int64_t _4_n) {
    int64_t _4_t1;
    struct0 _4_t0;
    struct0 _4_$retval;
    _4_t1 = 0;
    if (_4_t1 == _4_n % 15) {
        goto BB4;
    } else {
        goto BB7;
    }
BB7:
    if (_4_t1 == _4_n % 5) {
        goto BB10;
    } else {
        goto BB11;
    }
BB11:
    if (_4_t1 == _4_n % 3) {
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
    _4_t0 = (struct0) {.tag=0, ._0=(struct1) {string_2, 5}};
    goto BB6;
BB10:
    _4_t0 = (struct0) {.tag=0, ._0=(struct1) {string_1, 5}};
    goto BB6;
BB4:
    _4_t0 = (struct0) {.tag=0, ._0=(struct1) {string_0, 9}};
    goto BB6;
}

int main()
{
  printf("%s",_2_main()._0);
  return 0;
}
