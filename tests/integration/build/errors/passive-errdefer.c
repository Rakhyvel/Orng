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
int64_t _320_main(void);
struct2 _322_f(int64_t* _322_x,uint8_t _322_fail);

/* Function definitions */
int64_t _320_main(void) {
    int64_t _321_z;
    int64_t _321_y;
    function0 _320_t2;
    int64_t* _320_t4;
    uint8_t _320_t5;
    struct2 _320_t3;
    function0 _320_t7;
    int64_t* _320_t9;
    uint8_t _320_t10;
    struct2 _320_t8;
    int64_t _320_$retval;
    _321_z = 10;
    _321_y = 10;
    _320_t2 = _322_f;
    _320_t4 = &_321_z;
    _320_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _320_t3 = _320_t2(_320_t4, _320_t5);
    $line_idx--;
    (void)_320_t3;
    _320_t7 = _322_f;
    _320_t9 = &_321_y;
    _320_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _320_t8 = _320_t7(_320_t9, _320_t10);
    $line_idx--;
    (void)_320_t8;
    _320_$retval = $add_int64_t(_321_z, _321_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _320_$retval;
}

struct2 _322_f(int64_t* _322_x,uint8_t _322_fail) {
    struct2 _322_$retval;
    int64_t _322_t5;
    int64_t _322_t12;
    *_322_x = 6;
    if (_322_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _322_t5 = 100;
    *_322_x = $add_int64_t(*_322_x, _322_t5, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _322_t12 = 9;
    *_322_x = $add_int64_t(*_322_x, _322_t12, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _322_$retval;
BB9:
    _322_$retval = (struct2) {.tag=0};
    return _322_$retval;
}

int main(void) {
  printf("%ld",_320_main());
  return 0;
}
