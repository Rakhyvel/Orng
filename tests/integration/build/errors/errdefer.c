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
int64_t _597_main(void);
struct struct2 _599_f(int64_t* _599_x, uint8_t _599_fail);


/* Function definitions */
int64_t _597_main(void){
    int64_t _598_x;
    int64_t _598_y;
    function0 _597_t4;
    int64_t* _597_t6;
    uint8_t _597_t7;
    function0 _597_t9;
    int64_t* _597_t11;
    uint8_t _597_t12;
    int64_t _597_$retval;
    _598_x = 10;
    _598_y = 10;
    _597_t4 = (function0) _599_f;
    _597_t6 = &_598_x;
    _597_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    (void) _597_t4(_597_t6, _597_t7);
    $line_idx--;
    _597_t9 = (function0) _599_f;
    _597_t11 = &_598_y;
    _597_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _597_t9(_597_t11, _597_t12);
    $line_idx--;
    _597_$retval = $add_int64_t(_598_x, _598_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _597_$retval;
}

struct struct2 _599_f(int64_t* _599_x, uint8_t _599_fail){
    struct struct2 _599_$retval;
    *_599_x = 4;
    if (_599_fail) {
        goto BB683;
    } else {
        goto BB686;
    }
BB683:
    _599_$retval = (struct struct2) {.tag=1};
    *_599_x = 115;
    return _599_$retval;
BB686:
    _599_$retval = (struct struct2) {.tag=0};
    return _599_$retval;
}


int main(void) {
  printf("%ld",_597_main());
  return 0;
}
