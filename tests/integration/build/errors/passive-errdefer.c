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
int64_t _556_main(void);
struct2 _558_f(int64_t* _558_x,uint8_t _558_fail);

/* Function definitions */
int64_t _556_main(void){
    int64_t _557_z;
    int64_t _557_y;
    function0 _556_t2;
    int64_t* _556_t4;
    uint8_t _556_t5;
    struct2 _556_t3;
    function0 _556_t7;
    int64_t* _556_t9;
    uint8_t _556_t10;
    struct2 _556_t8;
    int64_t _556_$retval;
    _557_z = 10;
    _557_y = 10;
    _556_t2 = _558_f;
    _556_t4 = &_557_z;
    _556_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _556_t3 = _556_t2(_556_t4, _556_t5);
    $line_idx--;
    (void)_556_t3;
    _556_t7 = _558_f;
    _556_t9 = &_557_y;
    _556_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _556_t8 = _556_t7(_556_t9, _556_t10);
    $line_idx--;
    (void)_556_t8;
    _556_$retval = $add_int64_t(_557_z, _557_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _556_$retval;
}

struct2 _558_f(int64_t* _558_x,uint8_t _558_fail){
    struct2 _558_$retval;
    int64_t _558_t6;
    int64_t _558_t14;
    *_558_x = 6;
    if (_558_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _558_t6 = 100;
    *_558_x = $add_int64_t(*_558_x, _558_t6, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _558_t14 = 9;
    *_558_x = $add_int64_t(*_558_x, _558_t14, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _558_$retval;
BB9:
    _558_$retval = (struct2) {.tag=0};
    return _558_$retval;
}

int main(void) {
  printf("%ld",_556_main());
  return 0;
}
