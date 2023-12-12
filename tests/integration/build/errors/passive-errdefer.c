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
int64_t _380_main(void);
struct2 _382_f(int64_t* _382_x,uint8_t _382_fail);

/* Function definitions */
int64_t _380_main(void) {
    int64_t _381_z;
    int64_t _381_y;
    function0 _380_t2;
    int64_t* _380_t4;
    uint8_t _380_t5;
    struct2 _380_t3;
    function0 _380_t7;
    int64_t* _380_t9;
    uint8_t _380_t10;
    struct2 _380_t8;
    int64_t _380_$retval;
    _381_z = 10;
    _381_y = 10;
    _380_t2 = _382_f;
    _380_t4 = &_381_z;
    _380_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _380_t3 = _380_t2(_380_t4, _380_t5);
    $line_idx--;
    (void)_380_t3;
    _380_t7 = _382_f;
    _380_t9 = &_381_y;
    _380_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _380_t8 = _380_t7(_380_t9, _380_t10);
    $line_idx--;
    (void)_380_t8;
    _380_$retval = $add_int64_t(_381_z, _381_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _380_$retval;
}

struct2 _382_f(int64_t* _382_x,uint8_t _382_fail) {
    struct2 _382_$retval;
    int64_t _382_t6;
    int64_t _382_t14;
    *_382_x = 6;
    if (_382_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _382_t6 = 100;
    *_382_x = $add_int64_t(*_382_x, _382_t6, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _382_t14 = 9;
    *_382_x = $add_int64_t(*_382_x, _382_t14, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _382_$retval;
BB9:
    _382_$retval = (struct2) {.tag=0};
    return _382_$retval;
}

int main(void) {
  printf("%ld",_380_main());
  return 0;
}
