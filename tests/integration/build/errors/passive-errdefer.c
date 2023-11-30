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
int64_t _510_main(void);
struct2 _512_f(int64_t* _512_x,uint8_t _512_fail);

/* Function definitions */
int64_t _510_main(void) {
    int64_t _511_z;
    int64_t _511_y;
    function0 _510_t2;
    int64_t* _510_t4;
    uint8_t _510_t5;
    struct2 _510_t3;
    function0 _510_t7;
    int64_t* _510_t9;
    uint8_t _510_t10;
    struct2 _510_t8;
    int64_t _510_$retval;
    _511_z = 10;
    _511_y = 10;
    _510_t2 = _512_f;
    _510_t4 = &_511_z;
    _510_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _510_t3 = _510_t2(_510_t4, _510_t5);
    $line_idx--;
    (void)_510_t3;
    _510_t7 = _512_f;
    _510_t9 = &_511_y;
    _510_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _510_t8 = _510_t7(_510_t9, _510_t10);
    $line_idx--;
    (void)_510_t8;
    _510_$retval = $add_int64_t(_511_z, _511_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _510_$retval;
}

struct2 _512_f(int64_t* _512_x,uint8_t _512_fail) {
    struct2 _512_$retval;
    int64_t _512_t5;
    int64_t _512_t12;
    *_512_x = 6;
    if (_512_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _512_t5 = 100;
    *_512_x = $add_int64_t(*_512_x, _512_t5, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _512_t12 = 9;
    *_512_x = $add_int64_t(*_512_x, _512_t12, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _512_$retval;
BB9:
    _512_$retval = (struct2) {.tag=0};
    return _512_$retval;
}

int main(void) {
  printf("%ld",_510_main());
  return 0;
}
