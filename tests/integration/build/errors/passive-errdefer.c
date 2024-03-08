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
int64_t _634_main(void);
struct struct2 _636_f(int64_t* _636_x, uint8_t _636_fail);


/* Function definitions */
int64_t _634_main(void){
    int64_t _635_z;
    int64_t _635_y;
    function0 _634_t2;
    int64_t* _634_t4;
    uint8_t _634_t5;
    function0 _634_t7;
    int64_t* _634_t9;
    uint8_t _634_t10;
    int64_t _634_$retval;
    _635_z = 10;
    _635_y = 10;
    _634_t2 = (function0) _636_f;
    _634_t4 = &_635_z;
    _634_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    (void) _634_t2(_634_t4, _634_t5);
    $line_idx--;
    _634_t7 = (function0) _636_f;
    _634_t9 = &_635_y;
    _634_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _634_t7(_634_t9, _634_t10);
    $line_idx--;
    _634_$retval = $add_int64_t(_635_z, _635_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _634_$retval;
}

struct struct2 _636_f(int64_t* _636_x, uint8_t _636_fail){
    struct struct2 _636_$retval;
    int64_t _636_t5;
    int64_t _636_t12;
    *_636_x = 6;
    if (_636_fail) {
        goto BB754;
    } else {
        goto BB755;
    }
BB754:
    _636_t5 = 100;
    *_636_x = $add_int64_t(*_636_x, _636_t5, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _636_t12 = 9;
    *_636_x = $add_int64_t(*_636_x, _636_t12, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _636_$retval;
BB755:
    _636_$retval = (struct struct2) {.tag=0};
    return _636_$retval;
}


int main(void) {
  printf("%ld",_634_main());
  return 0;
}
