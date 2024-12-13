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
int64_t _622_main(void);
struct struct2 _624_f(int64_t* _624_x, uint8_t _624_fail);


/* Function definitions */
int64_t _622_main(void){
    int64_t _623_z;
    int64_t _623_y;
    function0 _622_t4;
    int64_t* _622_t6;
    uint8_t _622_t7;
    function0 _622_t9;
    int64_t* _622_t11;
    uint8_t _622_t12;
    int64_t _622_$retval;
    _623_z = 10;
    _623_y = 10;
    _622_t4 = (function0) _624_f;
    _622_t6 = &_623_z;
    _622_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    (void) _622_t4(_622_t6, _622_t7);
    $line_idx--;
    _622_t9 = (function0) _624_f;
    _622_t11 = &_623_y;
    _622_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _622_t9(_622_t11, _622_t12);
    $line_idx--;
    _622_$retval = $add_int64_t(_623_z, _623_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _622_$retval;
}

struct struct2 _624_f(int64_t* _624_x, uint8_t _624_fail){
    struct struct2 _624_$retval;
    int64_t _624_t8;
    int64_t _624_t16;
    *_624_x = 6;
    if (_624_fail) {
        goto BB715;
    } else {
        goto BB716;
    }
BB715:
    _624_t8 = 100;
    *_624_x = $add_int64_t(*_624_x, _624_t8, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _624_t16 = 9;
    *_624_x = $add_int64_t(*_624_x, _624_t16, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _624_$retval;
BB716:
    _624_$retval = (struct struct2) {.tag=0};
    return _624_$retval;
}


int main(void) {
  printf("%ld",_622_main());
  return 0;
}
