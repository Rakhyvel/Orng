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
int64_t _46_main(void);
struct2 _48_f(int64_t* _48_x,uint8_t _48_fail);

/* Function definitions */
int64_t _46_main(void) {
    int64_t _47_z;
    int64_t _47_y;
    function0 _46_t2;
    int64_t* _46_t4;
    uint8_t _46_t5;
    struct2 _46_t3;
    function0 _46_t7;
    int64_t* _46_t9;
    uint8_t _46_t10;
    struct2 _46_t8;
    int64_t _46_$retval;
    _47_z = 10;
    _47_y = 10;
    _46_t2 = _48_f;
    _46_t4 = &_47_z;
    _46_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _46_t3 = _46_t2(_46_t4, _46_t5);
    $line_idx--;
    (void)_46_t3;
    _46_t7 = _48_f;
    _46_t9 = &_47_y;
    _46_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _46_t8 = _46_t7(_46_t9, _46_t10);
    $line_idx--;
    (void)_46_t8;
    _46_$retval = $add_int64_t(_47_z, _47_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _46_$retval;
}

struct2 _48_f(int64_t* _48_x,uint8_t _48_fail) {
    struct2 _48_t2;
    uint8_t _48_t4;
    struct2 _48_t1;
    uint64_t _48_t10;
    uint8_t _48_t11;
    struct2 _48_t7;
    uint8_t _48_t9;
    struct2 _48_$retval;
    int64_t _48_t12;
    int64_t _48_t5;
    *_48_x = 6;
    if (_48_fail) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _48_t2 = (struct2) {.tag=1};
    _48_t4 = 0;
    if (_48_t4) {
        goto BB3;
    } else {
        goto BB8;
    }
BB9:
    _48_t7 = (struct2) {.tag=0};
    _48_t9 = 1;
    if (_48_t9) {
        goto BB11;
    } else {
        goto BB7;
    }
BB3:
    _48_t1 = _48_t2;
    goto BB4;
BB8:
    _48_t5 = 100;
    *_48_x = $add_int64_t(*_48_x, _48_t5, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    goto BB7;
BB11:
    _48_t1 = _48_t7;
    goto BB4;
BB7:
    _48_t12 = 9;
    *_48_x = $add_int64_t(*_48_x, _48_t12, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _48_$retval;
BB4:
    _48_t10 = _48_t1.tag;
    _48_t11 = !_48_t10;
    if (_48_t11) {
        goto BB6;
    } else {
        goto BB7;
    }
BB6:
    _48_$retval = _48_t1;
    return _48_$retval;
}

int main(void) {
  printf("%ld",_46_main());
  return 0;
}
