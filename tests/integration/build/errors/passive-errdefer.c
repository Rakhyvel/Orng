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
int64_t _600_main(void);
struct struct2 _602_f(int64_t* _602_x, uint8_t _602_fail);


/* Function definitions */
int64_t _600_main(void){
    int64_t _601_z;
    int64_t _601_y;
    function0 _600_t4;
    int64_t* _600_t6;
    uint8_t _600_t7;
    function0 _600_t9;
    int64_t* _600_t11;
    uint8_t _600_t12;
    int64_t _600_$retval;
    _601_z = 10;
    _601_y = 10;
    _600_t4 = (function0) _602_f;
    _600_t6 = &_601_z;
    _600_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    (void) _600_t4(_600_t6, _600_t7);
    $line_idx--;
    _600_t9 = (function0) _602_f;
    _600_t11 = &_601_y;
    _600_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _600_t9(_600_t11, _600_t12);
    $line_idx--;
    _600_$retval = $add_int64_t(_601_z, _601_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _600_$retval;
}

struct struct2 _602_f(int64_t* _602_x, uint8_t _602_fail){
    struct struct2 _602_$retval;
    int64_t _602_t8;
    int64_t _602_t16;
    *_602_x = 6;
    if (_602_fail) {
        goto BB694;
    } else {
        goto BB695;
    }
BB694:
    _602_t8 = 100;
    *_602_x = $add_int64_t(*_602_x, _602_t8, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _602_t16 = 9;
    *_602_x = $add_int64_t(*_602_x, _602_t16, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _602_$retval;
BB695:
    _602_$retval = (struct struct2) {.tag=0};
    return _602_$retval;
}


int main(void) {
  printf("%ld",_600_main());
  return 0;
}
