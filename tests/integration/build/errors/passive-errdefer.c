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
int64_t _595_main(void);
struct2 _597_f(int64_t* _597_x,uint8_t _597_fail);

/* Function definitions */
int64_t _595_main(void){
    int64_t _596_z;
    int64_t _596_y;
    function0 _595_t2;
    int64_t* _595_t4;
    uint8_t _595_t5;
    struct2 _595_t3;
    function0 _595_t7;
    int64_t* _595_t9;
    uint8_t _595_t10;
    struct2 _595_t8;
    int64_t _595_$retval;
    _596_z = 10;
    _596_y = 10;
    _595_t2 = _597_f;
    _595_t4 = &_596_z;
    _595_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _595_t3 = _595_t2(_595_t4, _595_t5);
    $line_idx--;
    (void)_595_t3;
    _595_t7 = _597_f;
    _595_t9 = &_596_y;
    _595_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _595_t8 = _595_t7(_595_t9, _595_t10);
    $line_idx--;
    (void)_595_t8;
    _595_$retval = $add_int64_t(_596_z, _596_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _595_$retval;
}

struct2 _597_f(int64_t* _597_x,uint8_t _597_fail){
    struct2 _597_$retval;
    int64_t _597_t5;
    int64_t _597_t12;
    *_597_x = 6;
    if (_597_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _597_t5 = 100;
    *_597_x = $add_int64_t(*_597_x, _597_t5, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _597_t12 = 9;
    *_597_x = $add_int64_t(*_597_x, _597_t12, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _597_$retval;
BB9:
    _597_$retval = (struct2) {.tag=0};
    return _597_$retval;
}

int main(void) {
  printf("%ld",_595_main());
  return 0;
}
