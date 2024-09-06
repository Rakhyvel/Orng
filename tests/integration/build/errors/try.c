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
int64_t _616_main(void);
struct struct1 _618_f(uint8_t _618_fail);
struct struct1 _623_g(void);


/* Function definitions */
int64_t _616_main(void){
    function0 _616_t1;
    uint8_t _616_t3;
    struct struct1 _616_t2;
    int64_t _616_t4;
    uint64_t _616_t5;
    int64_t _616_t0;
    function0 _616_t7;
    uint8_t _616_t9;
    struct struct1 _616_t8;
    int64_t _616_t10;
    uint64_t _616_t11;
    int64_t _616_t6;
    int64_t _616_$retval;
    _616_t1 = (function0) _618_f;
    _616_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _616_t2 = _616_t1(_616_t3);
    $line_idx--;
    _616_t4 = 122;
    _616_t5 = _616_t2.tag;
    if (_616_t5) {
        goto BB719;
    } else {
        goto BB725;
    }
BB719:
    _616_t0 = _616_t4;
    goto BB720;
BB725:
    _616_t0 = _616_t2._0;
    goto BB720;
BB720:
    _616_t7 = (function0) _618_f;
    _616_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _616_t8 = _616_t7(_616_t9);
    $line_idx--;
    _616_t10 = 122;
    _616_t11 = _616_t8.tag;
    if (_616_t11) {
        goto BB721;
    } else {
        goto BB724;
    }
BB721:
    _616_t6 = _616_t10;
    goto BB722;
BB724:
    _616_t6 = _616_t8._0;
    goto BB722;
BB722:
    _616_$retval = $add_int64_t(_616_t0, _616_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _616_$retval;
}

struct struct1 _618_f(uint8_t _618_fail){
    function2 _618_t1;
    struct struct1 _618_t2;
    uint64_t _618_t3;
    struct struct1 _618_$retval;
    int64_t _618_t6;
    struct struct1 _618_t0;
    int64_t _621_x;
    if (_618_fail) {
        goto BB709;
    } else {
        goto BB716;
    }
BB709:
    _618_t1 = (function2) _623_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _618_t2 = _618_t1();
    $line_idx--;
    _618_t3 = _618_t2.tag;
    if (_618_t3) {
        goto BB710;
    } else {
        goto BB712;
    }
BB716:
    _618_t6 = 0;
    _618_t0 = (struct struct1) {.tag=0, ._0=_618_t6};
    goto BB715;
BB710:
    _618_$retval = _618_t2;
    return _618_$retval;
BB712:
    _621_x = _618_t2._0;
    _618_t0 = (struct struct1) {.tag=0, ._0=_621_x};
    goto BB715;
BB715:
    _618_$retval = _618_t0;
    return _618_$retval;
}

struct struct1 _623_g(void){
    struct struct1 _623_$retval;
    _623_$retval = (struct struct1) {.tag=1};
    return _623_$retval;
}


int main(void) {
  printf("%ld",_616_main());
  return 0;
}
