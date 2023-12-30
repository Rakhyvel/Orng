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
int64_t _607_main(void);
struct2 _609_f(int64_t* _609_x, uint8_t _609_fail);

/* Function definitions */
int64_t _607_main(void){
    int64_t _608_z;
    int64_t _608_y;
    function0 _607_t2;
    int64_t* _607_t4;
    uint8_t _607_t5;
    struct2 _607_t3;
    function0 _607_t7;
    int64_t* _607_t9;
    uint8_t _607_t10;
    struct2 _607_t8;
    int64_t _607_$retval;
    _608_z = 10;
    _608_y = 10;
    _607_t2 = _609_f;
    _607_t4 = &_608_z;
    _607_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _607_t3 = _607_t2(_607_t4, _607_t5);
    $line_idx--;
    (void)_607_t3;
    _607_t7 = _609_f;
    _607_t9 = &_608_y;
    _607_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _607_t8 = _607_t7(_607_t9, _607_t10);
    $line_idx--;
    (void)_607_t8;
    _607_$retval = $add_int64_t(_608_z, _608_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _607_$retval;
}

struct2 _609_f(int64_t* _609_x, uint8_t _609_fail){
    struct2 _609_$retval;
    int64_t _609_t5;
    int64_t _609_t12;
    *_609_x = 6;
    if (_609_fail) {
        goto BB742;
    } else {
        goto BB743;
    }
BB742:
    _609_t5 = 100;
    *_609_x = $add_int64_t(*_609_x, _609_t5, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _609_t12 = 9;
    *_609_x = $add_int64_t(*_609_x, _609_t12, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _609_$retval;
BB743:
    _609_$retval = (struct2) {.tag=0};
    return _609_$retval;
}

int main(void) {
  printf("%ld",_607_main());
  return 0;
}
