/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
    };
};

typedef struct struct1(*function0)(uint8_t);

typedef struct struct1(*function2)(void);

/* Function forward definitions */
int64_t _642_main(void);
struct struct1 _644_f(uint8_t _644_fail);
struct struct1 _649_g(void);


/* Function definitions */
int64_t _642_main(void){
    function0 _642_t1;
    uint8_t _642_t3;
    struct struct1 _642_t2;
    uint64_t _642_t4;
    int64_t _642_t0;
    function0 _642_t7;
    uint8_t _642_t9;
    struct struct1 _642_t8;
    uint64_t _642_t10;
    int64_t _642_t6;
    int64_t _642_$retval;
    _642_t1 = _644_f;
    _642_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _642_t2 = _642_t1(_642_t3);
    $line_idx--;
    _642_t4 = _642_t2.tag;
    if (_642_t4) {
        goto BB773;
    } else {
        goto BB779;
    }
BB773:
    _642_t0 = 122;
    goto BB774;
BB779:
    _642_t0 = _642_t2._0;
    goto BB774;
BB774:
    _642_t7 = _644_f;
    _642_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _642_t8 = _642_t7(_642_t9);
    $line_idx--;
    _642_t10 = _642_t8.tag;
    if (_642_t10) {
        goto BB775;
    } else {
        goto BB778;
    }
BB775:
    _642_t6 = 122;
    goto BB776;
BB778:
    _642_t6 = _642_t8._0;
    goto BB776;
BB776:
    _642_$retval = $add_int64_t(_642_t0, _642_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _642_$retval;
}

struct struct1 _644_f(uint8_t _644_fail){
    function2 _644_t1;
    struct struct1 _644_t2;
    uint64_t _644_t3;
    struct struct1 _644_$retval;
    int64_t _644_t5;
    struct struct1 _644_t0;
    int64_t _647_x;
    if (_644_fail) {
        goto BB763;
    } else {
        goto BB770;
    }
BB763:
    _644_t1 = _649_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _644_t2 = _644_t1();
    $line_idx--;
    _644_t3 = _644_t2.tag;
    if (_644_t3) {
        goto BB764;
    } else {
        goto BB766;
    }
BB770:
    _644_t5 = 0;
    _644_t0 = (struct struct1) {.tag=0, ._0=_644_t5};
    goto BB769;
BB764:
    _644_$retval = _644_t2;
    return _644_$retval;
BB766:
    _647_x = _644_t2._0;
    _644_t0 = (struct struct1) {.tag=0, ._0=_647_x};
    goto BB769;
BB769:
    _644_$retval = _644_t0;
    return _644_$retval;
}

struct struct1 _649_g(void){
    struct struct1 _649_$retval;
    _649_$retval = (struct struct1) {.tag=1};
    return _649_$retval;
}


int main(void) {
  printf("%ld",_642_main());
  return 0;
}
