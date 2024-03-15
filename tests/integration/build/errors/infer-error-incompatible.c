/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct3;

/* Struct, union, and function definitions */
struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
};

typedef struct struct1(*function0)(void);

struct struct3 {
    uint64_t tag;
    union {
        int64_t _0;
        uint8_t _1;
    };
};

typedef struct struct3(*function2)(void);

/* Function forward definitions */
int64_t _2_main(void);
struct struct1 _4_h(void);
struct struct1 _6_f(void);
struct struct3 _8_g(void);


/* Function definitions */
int64_t _2_main(void){
    function0 _2_t1;
    _2_t1 = (function0) _4_h;
    $lines[$line_idx++] = "tests/integration/errors/infer-error-incompatible.orng:2:7:\n    h() catch unreachable\n     ^";
    (void) _2_t1();
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/errors/infer-error-incompatible.orng:2:26:\n    h() catch unreachable\n                        ^";
    $panic("reached unreachable code\n");
}

struct struct1 _4_h(void){
    function0 _4_t0;
    struct struct1 _4_t1;
    uint64_t _4_t2;
    struct struct1 _4_$retval;
    int64_t _4_t6;
    function2 _4_t3;
    struct struct3 _4_t4;
    uint64_t _4_t5;
    _4_t0 = (function0) _6_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-error-incompatible.orng:6:15:\n    .ok(try f() + try g())\n             ^";
    _4_t1 = _4_t0();
    $line_idx--;
    _4_t2 = _4_t1.tag;
    if (_4_t2) {
        goto BB5;
    } else {
        goto BB7;
    }
BB5:
    _4_$retval = _4_t1;
    return _4_$retval;
BB7:
    _4_t3 = (function2) _8_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-error-incompatible.orng:6:25:\n    .ok(try f() + try g())\n                       ^";
    _4_t4 = _4_t3();
    $line_idx--;
    _4_t5 = _4_t4.tag;
    if (_4_t5) {
        goto BB8;
    } else {
        goto BB10;
    }
BB8:
    _4_$retval = _4_t4;
    return _4_$retval;
BB10:
    _4_t6 = $add_int64_t(_4_t1._0, _4_t4._0, "tests/integration/errors/infer-error-incompatible.orng:6:18:\n    .ok(try f() + try g())\n                ^");
    _4_$retval = (struct struct1) {.tag=0, ._0=_4_t6};
    return _4_$retval;
}

struct struct1 _6_f(void){
    int64_t _6_t0;
    struct struct1 _6_$retval;
    _6_t0 = 4;
    _6_$retval = (struct struct1) {.tag=1, ._1=_6_t0};
    return _6_$retval;
}

struct struct3 _8_g(void){
    uint8_t _8_t0;
    struct struct3 _8_$retval;
    _8_t0 = 0;
    _8_$retval = (struct struct3) {.tag=1, ._1=_8_t0};
    return _8_$retval;
}


int main(void) {
  printf("%ld",_2_main());
  return 0;
}
