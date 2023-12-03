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
int64_t _312_main(void);
struct2 _314_f(int64_t* _314_x,uint8_t _314_fail);

/* Function definitions */
int64_t _312_main(void) {
    int64_t _313_x;
    int64_t _313_y;
    function0 _312_t2;
    int64_t* _312_t4;
    uint8_t _312_t5;
    struct2 _312_t3;
    function0 _312_t7;
    int64_t* _312_t9;
    uint8_t _312_t10;
    struct2 _312_t8;
    int64_t _312_$retval;
    _313_x = 10;
    _313_y = 10;
    _312_t2 = _314_f;
    _312_t4 = &_313_x;
    _312_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _312_t3 = _312_t2(_312_t4, _312_t5);
    $line_idx--;
    (void)_312_t3;
    _312_t7 = _314_f;
    _312_t9 = &_313_y;
    _312_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _312_t8 = _312_t7(_312_t9, _312_t10);
    $line_idx--;
    (void)_312_t8;
    _312_$retval = $add_int64_t(_313_x, _313_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _312_$retval;
}

struct2 _314_f(int64_t* _314_x,uint8_t _314_fail) {
    struct2 _314_$retval;
    *_314_x = 4;
    if (_314_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _314_$retval = (struct2) {.tag=1};
    *_314_x = 115;
    return _314_$retval;
BB4:
    _314_$retval = (struct2) {.tag=0};
    return _314_$retval;
}

int main(void) {
  printf("%ld",_312_main());
  return 0;
}
