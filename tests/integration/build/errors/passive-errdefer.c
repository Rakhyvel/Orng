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
int64_t _537_main(void);
struct2 _539_f(int64_t* _539_x,uint8_t _539_fail);

/* Function definitions */
int64_t _537_main(void) {
    int64_t _538_z;
    int64_t _538_y;
    function0 _537_t2;
    int64_t* _537_t4;
    uint8_t _537_t5;
    struct2 _537_t3;
    function0 _537_t7;
    int64_t* _537_t9;
    uint8_t _537_t10;
    struct2 _537_t8;
    int64_t _537_$retval;
    _538_z = 10;
    _538_y = 10;
    _537_t2 = _539_f;
    _537_t4 = &_538_z;
    _537_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _537_t3 = _537_t2(_537_t4, _537_t5);
    $line_idx--;
    (void)_537_t3;
    _537_t7 = _539_f;
    _537_t9 = &_538_y;
    _537_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _537_t8 = _537_t7(_537_t9, _537_t10);
    $line_idx--;
    (void)_537_t8;
    _537_$retval = $add_int64_t(_538_z, _538_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _537_$retval;
}

struct2 _539_f(int64_t* _539_x,uint8_t _539_fail) {
    struct2 _539_$retval;
    int64_t _539_t6;
    int64_t _539_t14;
    *_539_x = 6;
    if (_539_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _539_t6 = 100;
    *_539_x = $add_int64_t(*_539_x, _539_t6, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _539_t14 = 9;
    *_539_x = $add_int64_t(*_539_x, _539_t14, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _539_$retval;
BB9:
    _539_$retval = (struct2) {.tag=0};
    return _539_$retval;
}

int main(void) {
  printf("%ld",_537_main());
  return 0;
}
