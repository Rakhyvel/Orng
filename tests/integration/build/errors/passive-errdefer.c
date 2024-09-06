/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t* _0;
    uint8_t _1;
};

struct struct2 {
    uint64_t tag;
};

typedef struct struct2(*function0)(int64_t*, uint8_t);

/* Function forward definitions */
int64_t _608_main(void);
struct struct2 _610_f(int64_t* _610_x, uint8_t _610_fail);


/* Function definitions */
int64_t _608_main(void){
    int64_t _609_z;
    int64_t _609_y;
    function0 _608_t4;
    int64_t* _608_t6;
    uint8_t _608_t7;
    function0 _608_t9;
    int64_t* _608_t11;
    uint8_t _608_t12;
    int64_t _608_$retval;
    _609_z = 10;
    _609_y = 10;
    _608_t4 = (function0) _610_f;
    _608_t6 = &_609_z;
    _608_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    (void) _608_t4(_608_t6, _608_t7);
    $line_idx--;
    _608_t9 = (function0) _610_f;
    _608_t11 = &_609_y;
    _608_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _608_t9(_608_t11, _608_t12);
    $line_idx--;
    _608_$retval = $add_int64_t(_609_z, _609_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _608_$retval;
}

struct struct2 _610_f(int64_t* _610_x, uint8_t _610_fail){
    struct struct2 _610_$retval;
    int64_t _610_t8;
    int64_t _610_t16;
    *_610_x = 6;
    if (_610_fail) {
        goto BB700;
    } else {
        goto BB701;
    }
BB700:
    _610_t8 = 100;
    *_610_x = $add_int64_t(*_610_x, _610_t8, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _610_t16 = 9;
    *_610_x = $add_int64_t(*_610_x, _610_t16, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _610_$retval;
BB701:
    _610_$retval = (struct struct2) {.tag=0};
    return _610_$retval;
}


int main(void) {
  printf("%ld",_608_main());
  return 0;
}
