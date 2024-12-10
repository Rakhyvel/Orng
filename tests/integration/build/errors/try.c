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
int64_t _628_main(void);
struct struct1 _630_f(uint8_t _630_fail);
struct struct1 _635_g(void);


/* Function definitions */
int64_t _628_main(void){
    function0 _628_t1;
    uint8_t _628_t3;
    struct struct1 _628_t2;
    int64_t _628_t4;
    uint64_t _628_t5;
    int64_t _628_t0;
    function0 _628_t7;
    uint8_t _628_t9;
    struct struct1 _628_t8;
    int64_t _628_t10;
    uint64_t _628_t11;
    int64_t _628_t6;
    int64_t _628_$retval;
    _628_t1 = (function0) _630_f;
    _628_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _628_t2 = _628_t1(_628_t3);
    $line_idx--;
    _628_t4 = 122;
    _628_t5 = _628_t2.tag;
    if (_628_t5) {
        goto BB732;
    } else {
        goto BB738;
    }
BB732:
    _628_t0 = _628_t4;
    goto BB733;
BB738:
    _628_t0 = _628_t2._0;
    goto BB733;
BB733:
    _628_t7 = (function0) _630_f;
    _628_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _628_t8 = _628_t7(_628_t9);
    $line_idx--;
    _628_t10 = 122;
    _628_t11 = _628_t8.tag;
    if (_628_t11) {
        goto BB734;
    } else {
        goto BB737;
    }
BB734:
    _628_t6 = _628_t10;
    goto BB735;
BB737:
    _628_t6 = _628_t8._0;
    goto BB735;
BB735:
    _628_$retval = $add_int64_t(_628_t0, _628_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _628_$retval;
}

struct struct1 _630_f(uint8_t _630_fail){
    function2 _630_t1;
    struct struct1 _630_t2;
    uint64_t _630_t3;
    struct struct1 _630_$retval;
    int64_t _630_t6;
    struct struct1 _630_t0;
    int64_t _633_x;
    if (_630_fail) {
        goto BB722;
    } else {
        goto BB729;
    }
BB722:
    _630_t1 = (function2) _635_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _630_t2 = _630_t1();
    $line_idx--;
    _630_t3 = _630_t2.tag;
    if (_630_t3) {
        goto BB723;
    } else {
        goto BB725;
    }
BB729:
    _630_t6 = 0;
    _630_t0 = (struct struct1) {.tag=0, ._0=_630_t6};
    goto BB728;
BB723:
    _630_$retval = _630_t2;
    return _630_$retval;
BB725:
    _633_x = _630_t2._0;
    _630_t0 = (struct struct1) {.tag=0, ._0=_633_x};
    goto BB728;
BB728:
    _630_$retval = _630_t0;
    return _630_$retval;
}

struct struct1 _635_g(void){
    struct struct1 _635_$retval;
    _635_$retval = (struct struct1) {.tag=1};
    return _635_$retval;
}


int main(void) {
  printf("%ld",_628_main());
  return 0;
}
