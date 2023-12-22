/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
    };
} struct1;

typedef struct1(*function0)(uint8_t);

typedef struct1(*function2)(void);

/* Function forward definitions */
int64_t _603_main(void);
struct1 _605_f(uint8_t _605_fail);
struct1 _610_g(void);

/* Function definitions */
int64_t _603_main(void){
    function0 _603_t1;
    uint8_t _603_t3;
    struct1 _603_t2;
    uint64_t _603_t4;
    int64_t _603_t0;
    function0 _603_t7;
    uint8_t _603_t9;
    struct1 _603_t8;
    uint64_t _603_t10;
    int64_t _603_t6;
    int64_t _603_$retval;
    _603_t1 = _605_f;
    _603_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _603_t2 = _603_t1(_603_t3);
    $line_idx--;
    _603_t4 = _603_t2.tag;
    if (_603_t4) {
        goto BB777;
    } else {
        goto BB783;
    }
BB777:
    _603_t0 = 122;
    goto BB778;
BB783:
    _603_t0 = _603_t2._0;
    goto BB778;
BB778:
    _603_t7 = _605_f;
    _603_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _603_t8 = _603_t7(_603_t9);
    $line_idx--;
    _603_t10 = _603_t8.tag;
    if (_603_t10) {
        goto BB779;
    } else {
        goto BB782;
    }
BB779:
    _603_t6 = 122;
    goto BB780;
BB782:
    _603_t6 = _603_t8._0;
    goto BB780;
BB780:
    _603_$retval = $add_int64_t(_603_t0, _603_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _603_$retval;
}

struct1 _605_f(uint8_t _605_fail){
    function2 _605_t1;
    struct1 _605_t2;
    uint64_t _605_t3;
    struct1 _605_$retval;
    int64_t _605_t5;
    struct1 _605_t0;
    int64_t _608_x;
    if (_605_fail) {
        goto BB767;
    } else {
        goto BB774;
    }
BB767:
    _605_t1 = _610_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _605_t2 = _605_t1();
    $line_idx--;
    _605_t3 = _605_t2.tag;
    if (_605_t3) {
        goto BB768;
    } else {
        goto BB770;
    }
BB774:
    _605_t5 = 0;
    _605_t0 = (struct1) {.tag=0, ._0=_605_t5};
    goto BB773;
BB768:
    _605_$retval = _605_t2;
    return _605_$retval;
BB770:
    _608_x = _605_t2._0;
    _605_t0 = (struct1) {.tag=0, ._0=_608_x};
    goto BB773;
BB773:
    _605_$retval = _605_t0;
    return _605_$retval;
}

struct1 _610_g(void){
    struct1 _610_$retval;
    _610_$retval = (struct1) {.tag=1};
    return _610_$retval;
}

int main(void) {
  printf("%ld",_603_main());
  return 0;
}
