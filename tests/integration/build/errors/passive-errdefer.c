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
int64_t _392_main(void);
struct2 _394_f(int64_t* _394_x,uint8_t _394_fail);

/* Function definitions */
int64_t _392_main(void) {
    int64_t _393_z;
    int64_t _393_y;
    function0 _392_t2;
    int64_t* _392_t4;
    uint8_t _392_t5;
    struct2 _392_t3;
    function0 _392_t7;
    int64_t* _392_t9;
    uint8_t _392_t10;
    struct2 _392_t8;
    int64_t _392_$retval;
    _393_z = 10;
    _393_y = 10;
    _392_t2 = _394_f;
    _392_t4 = &_393_z;
    _392_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _392_t3 = _392_t2(_392_t4, _392_t5);
    $line_idx--;
    (void)_392_t3;
    _392_t7 = _394_f;
    _392_t9 = &_393_y;
    _392_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _392_t8 = _392_t7(_392_t9, _392_t10);
    $line_idx--;
    (void)_392_t8;
    _392_$retval = $add_int64_t(_393_z, _393_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _392_$retval;
}

struct2 _394_f(int64_t* _394_x,uint8_t _394_fail) {
    struct2 _394_$retval;
    int64_t _394_t5;
    int64_t _394_t12;
    *_394_x = 6;
    if (_394_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _394_t5 = 100;
    *_394_x = $add_int64_t(*_394_x, _394_t5, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _394_t12 = 9;
    *_394_x = $add_int64_t(*_394_x, _394_t12, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _394_$retval;
BB9:
    _394_$retval = (struct2) {.tag=0};
    return _394_$retval;
}

int main(void) {
  printf("%ld",_392_main());
  return 0;
}
