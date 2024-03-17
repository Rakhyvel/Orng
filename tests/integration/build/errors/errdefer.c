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
int64_t _589_main(void);
struct struct2 _591_f(int64_t* _591_x, uint8_t _591_fail);


/* Function definitions */
int64_t _589_main(void){
    int64_t _590_x;
    int64_t _590_y;
    function0 _589_t4;
    int64_t* _589_t6;
    uint8_t _589_t7;
    function0 _589_t9;
    int64_t* _589_t11;
    uint8_t _589_t12;
    int64_t _589_$retval;
    _590_x = 10;
    _590_y = 10;
    _589_t4 = (function0) _591_f;
    _589_t6 = &_590_x;
    _589_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    (void) _589_t4(_589_t6, _589_t7);
    $line_idx--;
    _589_t9 = (function0) _591_f;
    _589_t11 = &_590_y;
    _589_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _589_t9(_589_t11, _589_t12);
    $line_idx--;
    _589_$retval = $add_int64_t(_590_x, _590_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _589_$retval;
}

struct struct2 _591_f(int64_t* _591_x, uint8_t _591_fail){
    struct struct2 _591_$retval;
    *_591_x = 4;
    if (_591_fail) {
        goto BB677;
    } else {
        goto BB680;
    }
BB677:
    _591_$retval = (struct struct2) {.tag=1};
    *_591_x = 115;
    return _591_$retval;
BB680:
    _591_$retval = (struct struct2) {.tag=0};
    return _591_$retval;
}


int main(void) {
  printf("%ld",_589_main());
  return 0;
}
