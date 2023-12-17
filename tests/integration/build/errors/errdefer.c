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
int64_t _657_main(void);
struct2 _659_f(int64_t* _659_x,uint8_t _659_fail);

/* Function definitions */
int64_t _657_main(void){
    int64_t _658_x;
    int64_t _658_y;
    function0 _657_t2;
    int64_t* _657_t4;
    uint8_t _657_t5;
    struct2 _657_t3;
    function0 _657_t7;
    int64_t* _657_t9;
    uint8_t _657_t10;
    struct2 _657_t8;
    int64_t _657_$retval;
    _658_x = 10;
    _658_y = 10;
    _657_t2 = _659_f;
    _657_t4 = &_658_x;
    _657_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _657_t3 = _657_t2(_657_t4, _657_t5);
    $line_idx--;
    (void)_657_t3;
    _657_t7 = _659_f;
    _657_t9 = &_658_y;
    _657_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _657_t8 = _657_t7(_657_t9, _657_t10);
    $line_idx--;
    (void)_657_t8;
    _657_$retval = $add_int64_t(_658_x, _658_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _657_$retval;
}

struct2 _659_f(int64_t* _659_x,uint8_t _659_fail){
    struct2 _659_$retval;
    *_659_x = 4;
    if (_659_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _659_$retval = (struct2) {.tag=1};
    *_659_x = 115;
    return _659_$retval;
BB4:
    _659_$retval = (struct2) {.tag=0};
    return _659_$retval;
}

int main(void) {
  printf("%ld",_657_main());
  return 0;
}
