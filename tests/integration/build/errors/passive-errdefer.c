/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    uint8_t _1;
} struct1;

typedef struct {
    uint64_t tag;
} struct2;

typedef struct2(*function0)(int64_t*, uint8_t);

/* Function forward definitions */
int64_t _708_main(void);
struct2 _710_f(int64_t* _710_x,uint8_t _710_fail);

/* Function definitions */
int64_t _708_main(void){
    int64_t _709_z;
    int64_t _709_y;
    function0 _708_t2;
    int64_t* _708_t4;
    uint8_t _708_t5;
    struct2 _708_t3;
    function0 _708_t7;
    int64_t* _708_t9;
    uint8_t _708_t10;
    struct2 _708_t8;
    int64_t _708_$retval;
    _709_z = 10;
    _709_y = 10;
    _708_t2 = _710_f;
    _708_t4 = &_709_z;
    _708_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _708_t3 = _708_t2(_708_t4, _708_t5);
    $line_idx--;
    (void)_708_t3;
    _708_t7 = _710_f;
    _708_t9 = &_709_y;
    _708_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _708_t8 = _708_t7(_708_t9, _708_t10);
    $line_idx--;
    (void)_708_t8;
    _708_$retval = $add_int64_t(_709_z, _709_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _708_$retval;
}

struct2 _710_f(int64_t* _710_x,uint8_t _710_fail){
    struct2 _710_$retval;
    int64_t _710_t6;
    int64_t _710_t14;
    *_710_x = 6;
    if (_710_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _710_t6 = 100;
    *_710_x = $add_int64_t(*_710_x, _710_t6, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _710_t14 = 9;
    *_710_x = $add_int64_t(*_710_x, _710_t14, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _710_$retval;
BB9:
    _710_$retval = (struct2) {.tag=0};
    return _710_$retval;
}

int main(void) {
  printf("%ld",_708_main());
  return 0;
}
