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
int64_t _620_main(void);
struct struct2 _622_f(int64_t* _622_x, uint8_t _622_fail);


/* Function definitions */
int64_t _620_main(void){
    int64_t _621_z;
    int64_t _621_y;
    function0 _620_t4;
    int64_t* _620_t6;
    uint8_t _620_t7;
    function0 _620_t9;
    int64_t* _620_t11;
    uint8_t _620_t12;
    int64_t _620_$retval;
    _621_z = 10;
    _621_y = 10;
    _620_t4 = (function0) _622_f;
    _620_t6 = &_621_z;
    _620_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    (void) _620_t4(_620_t6, _620_t7);
    $line_idx--;
    _620_t9 = (function0) _622_f;
    _620_t11 = &_621_y;
    _620_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _620_t9(_620_t11, _620_t12);
    $line_idx--;
    _620_$retval = $add_int64_t(_621_z, _621_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _620_$retval;
}

struct struct2 _622_f(int64_t* _622_x, uint8_t _622_fail){
    struct struct2 _622_$retval;
    int64_t _622_t8;
    int64_t _622_t16;
    *_622_x = 6;
    if (_622_fail) {
        goto BB713;
    } else {
        goto BB714;
    }
BB713:
    _622_t8 = 100;
    *_622_x = $add_int64_t(*_622_x, _622_t8, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _622_t16 = 9;
    *_622_x = $add_int64_t(*_622_x, _622_t16, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _622_$retval;
BB714:
    _622_$retval = (struct struct2) {.tag=0};
    return _622_$retval;
}


int main(void) {
  printf("%ld",_620_main());
  return 0;
}
