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
int64_t _605_main(void);
struct struct2 _607_f(int64_t* _607_x, uint8_t _607_fail);


/* Function definitions */
int64_t _605_main(void){
    int64_t _606_z;
    int64_t _606_y;
    function0 _605_t4;
    int64_t* _605_t6;
    uint8_t _605_t7;
    function0 _605_t9;
    int64_t* _605_t11;
    uint8_t _605_t12;
    int64_t _605_$retval;
    _606_z = 10;
    _606_y = 10;
    _605_t4 = (function0) _607_f;
    _605_t6 = &_606_z;
    _605_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    (void) _605_t4(_605_t6, _605_t7);
    $line_idx--;
    _605_t9 = (function0) _607_f;
    _605_t11 = &_606_y;
    _605_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _605_t9(_605_t11, _605_t12);
    $line_idx--;
    _605_$retval = $add_int64_t(_606_z, _606_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _605_$retval;
}

struct struct2 _607_f(int64_t* _607_x, uint8_t _607_fail){
    struct struct2 _607_$retval;
    int64_t _607_t8;
    int64_t _607_t16;
    *_607_x = 6;
    if (_607_fail) {
        goto BB697;
    } else {
        goto BB698;
    }
BB697:
    _607_t8 = 100;
    *_607_x = $add_int64_t(*_607_x, _607_t8, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _607_t16 = 9;
    *_607_x = $add_int64_t(*_607_x, _607_t16, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _607_$retval;
BB698:
    _607_$retval = (struct struct2) {.tag=0};
    return _607_$retval;
}


int main(void) {
  printf("%ld",_605_main());
  return 0;
}
