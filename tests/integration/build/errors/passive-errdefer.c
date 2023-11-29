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
int64_t _508_main(void);
struct2 _510_f(int64_t* _510_x,uint8_t _510_fail);

/* Function definitions */
int64_t _508_main(void) {
    int64_t _509_z;
    int64_t _509_y;
    function0 _508_t2;
    int64_t* _508_t4;
    uint8_t _508_t5;
    struct2 _508_t3;
    function0 _508_t7;
    int64_t* _508_t9;
    uint8_t _508_t10;
    struct2 _508_t8;
    int64_t _508_$retval;
    _509_z = 10;
    _509_y = 10;
    _508_t2 = _510_f;
    _508_t4 = &_509_z;
    _508_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _508_t3 = _508_t2(_508_t4, _508_t5);
    $line_idx--;
    (void)_508_t3;
    _508_t7 = _510_f;
    _508_t9 = &_509_y;
    _508_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _508_t8 = _508_t7(_508_t9, _508_t10);
    $line_idx--;
    (void)_508_t8;
    _508_$retval = $add_int64_t(_509_z, _509_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _508_$retval;
}

struct2 _510_f(int64_t* _510_x,uint8_t _510_fail) {
    struct2 _510_$retval;
    int64_t _510_t5;
    int64_t _510_t12;
    *_510_x = 6;
    if (_510_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _510_t5 = 100;
    *_510_x = $add_int64_t(*_510_x, _510_t5, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _510_t12 = 9;
    *_510_x = $add_int64_t(*_510_x, _510_t12, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _510_$retval;
BB9:
    _510_$retval = (struct2) {.tag=0};
    return _510_$retval;
}

int main(void) {
  printf("%ld",_508_main());
  return 0;
}
