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
int64_t _16_main(void);
struct struct2 _18_f(int64_t* _18_x, uint8_t _18_fail);


/* Function definitions */
int64_t _16_main(void){
    int64_t _17_z;
    int64_t _17_y;
    function0 _16_t4;
    int64_t* _16_t6;
    uint8_t _16_t7;
    function0 _16_t9;
    int64_t* _16_t11;
    uint8_t _16_t12;
    int64_t _16_$retval;
    _17_z = 10;
    _17_y = 10;
    _16_t4 = (function0) _18_f;
    _16_t6 = &_17_z;
    _16_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    (void) _16_t4(_16_t6, _16_t7);
    $line_idx--;
    _16_t9 = (function0) _18_f;
    _16_t11 = &_17_y;
    _16_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _16_t9(_16_t11, _16_t12);
    $line_idx--;
    _16_$retval = $add_int64_t(_17_z, _17_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _16_$retval;
}

struct struct2 _18_f(int64_t* _18_x, uint8_t _18_fail){
    struct struct2 _18_$retval;
    int64_t _18_t7;
    int64_t _18_t14;
    *_18_x = 6;
    if (_18_fail) {
        goto BB23;
    } else {
        goto BB24;
    }
BB23:
    _18_t7 = 100;
    *_18_x = $add_int64_t(*_18_x, _18_t7, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _18_t14 = 9;
    *_18_x = $add_int64_t(*_18_x, _18_t14, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _18_$retval;
BB24:
    _18_$retval = (struct struct2) {.tag=0};
    return _18_$retval;
}


int main(void) {
  printf("%ld",_16_main());
  return 0;
}
