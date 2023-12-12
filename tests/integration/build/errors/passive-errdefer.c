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
int64_t _361_main(void);
struct2 _363_f(int64_t* _363_x,uint8_t _363_fail);

/* Function definitions */
int64_t _361_main(void) {
    int64_t _362_z;
    int64_t _362_y;
    function0 _361_t2;
    int64_t* _361_t4;
    uint8_t _361_t5;
    struct2 _361_t3;
    function0 _361_t7;
    int64_t* _361_t9;
    uint8_t _361_t10;
    struct2 _361_t8;
    int64_t _361_$retval;
    _362_z = 10;
    _362_y = 10;
    _361_t2 = _363_f;
    _361_t4 = &_362_z;
    _361_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _361_t3 = _361_t2(_361_t4, _361_t5);
    $line_idx--;
    (void)_361_t3;
    _361_t7 = _363_f;
    _361_t9 = &_362_y;
    _361_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _361_t8 = _361_t7(_361_t9, _361_t10);
    $line_idx--;
    (void)_361_t8;
    _361_$retval = $add_int64_t(_362_z, _362_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _361_$retval;
}

struct2 _363_f(int64_t* _363_x,uint8_t _363_fail) {
    struct2 _363_$retval;
    int64_t _363_t6;
    int64_t _363_t14;
    *_363_x = 6;
    if (_363_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _363_t6 = 100;
    *_363_x = $add_int64_t(*_363_x, _363_t6, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _363_t14 = 9;
    *_363_x = $add_int64_t(*_363_x, _363_t14, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _363_$retval;
BB9:
    _363_$retval = (struct2) {.tag=0};
    return _363_$retval;
}

int main(void) {
  printf("%ld",_361_main());
  return 0;
}
