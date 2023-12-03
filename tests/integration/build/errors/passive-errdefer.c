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
int64_t _353_main(void);
struct2 _355_f(int64_t* _355_x,uint8_t _355_fail);

/* Function definitions */
int64_t _353_main(void) {
    int64_t _354_z;
    int64_t _354_y;
    function0 _353_t2;
    int64_t* _353_t4;
    uint8_t _353_t5;
    struct2 _353_t3;
    function0 _353_t7;
    int64_t* _353_t9;
    uint8_t _353_t10;
    struct2 _353_t8;
    int64_t _353_$retval;
    _354_z = 10;
    _354_y = 10;
    _353_t2 = _355_f;
    _353_t4 = &_354_z;
    _353_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _353_t3 = _353_t2(_353_t4, _353_t5);
    $line_idx--;
    (void)_353_t3;
    _353_t7 = _355_f;
    _353_t9 = &_354_y;
    _353_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _353_t8 = _353_t7(_353_t9, _353_t10);
    $line_idx--;
    (void)_353_t8;
    _353_$retval = $add_int64_t(_354_z, _354_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _353_$retval;
}

struct2 _355_f(int64_t* _355_x,uint8_t _355_fail) {
    struct2 _355_$retval;
    int64_t _355_t6;
    int64_t _355_t14;
    *_355_x = 6;
    if (_355_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _355_t6 = 100;
    *_355_x = $add_int64_t(*_355_x, _355_t6, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _355_t14 = 9;
    *_355_x = $add_int64_t(*_355_x, _355_t14, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _355_$retval;
BB9:
    _355_$retval = (struct2) {.tag=0};
    return _355_$retval;
}

int main(void) {
  printf("%ld",_353_main());
  return 0;
}
