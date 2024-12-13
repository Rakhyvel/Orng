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
int64_t _630_main(void);
struct struct1 _632_f(uint8_t _632_fail);
struct struct1 _637_g(void);


/* Function definitions */
int64_t _630_main(void){
    function0 _630_t1;
    uint8_t _630_t3;
    struct struct1 _630_t2;
    uint64_t _630_t4;
    int64_t _630_t0;
    function0 _630_t7;
    uint8_t _630_t9;
    struct struct1 _630_t8;
    uint64_t _630_t10;
    int64_t _630_t6;
    int64_t _630_$retval;
    _630_t1 = (function0) _632_f;
    _630_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _630_t2 = _630_t1(_630_t3);
    $line_idx--;
    _630_t4 = _630_t2.tag;
    if (_630_t4) {
        goto BB734;
    } else {
        goto BB740;
    }
BB734:
    _630_t0 = 122;
    goto BB735;
BB740:
    _630_t0 = _630_t2._0;
    goto BB735;
BB735:
    _630_t7 = (function0) _632_f;
    _630_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _630_t8 = _630_t7(_630_t9);
    $line_idx--;
    _630_t10 = _630_t8.tag;
    if (_630_t10) {
        goto BB736;
    } else {
        goto BB739;
    }
BB736:
    _630_t6 = 122;
    goto BB737;
BB739:
    _630_t6 = _630_t8._0;
    goto BB737;
BB737:
    _630_$retval = $add_int64_t(_630_t0, _630_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _630_$retval;
}

struct struct1 _632_f(uint8_t _632_fail){
    function2 _632_t1;
    struct struct1 _632_t2;
    uint64_t _632_t3;
    struct struct1 _632_$retval;
    int64_t _632_t6;
    struct struct1 _632_t0;
    int64_t _635_x;
    if (_632_fail) {
        goto BB724;
    } else {
        goto BB731;
    }
BB724:
    _632_t1 = (function2) _637_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _632_t2 = _632_t1();
    $line_idx--;
    _632_t3 = _632_t2.tag;
    if (_632_t3) {
        goto BB725;
    } else {
        goto BB727;
    }
BB731:
    _632_t6 = 0;
    _632_t0 = (struct struct1) {.tag=0, ._0=_632_t6};
    goto BB730;
BB725:
    _632_$retval = _632_t2;
    return _632_$retval;
BB727:
    _635_x = _632_t2._0;
    _632_t0 = (struct struct1) {.tag=0, ._0=_635_x};
    goto BB730;
BB730:
    _632_$retval = _632_t0;
    return _632_$retval;
}

struct struct1 _637_g(void){
    struct struct1 _637_$retval;
    _637_$retval = (struct struct1) {.tag=1};
    return _637_$retval;
}


int main(void) {
  printf("%ld",_630_main());
  return 0;
}
