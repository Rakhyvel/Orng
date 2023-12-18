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
int64_t _664_main(void);
struct2 _666_f(int64_t* _666_x,uint8_t _666_fail);

/* Function definitions */
int64_t _664_main(void){
    int64_t _665_x;
    int64_t _665_y;
    function0 _664_t2;
    int64_t* _664_t4;
    uint8_t _664_t5;
    struct2 _664_t3;
    function0 _664_t7;
    int64_t* _664_t9;
    uint8_t _664_t10;
    struct2 _664_t8;
    int64_t _664_$retval;
    _665_x = 10;
    _665_y = 10;
    _664_t2 = _666_f;
    _664_t4 = &_665_x;
    _664_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _664_t3 = _664_t2(_664_t4, _664_t5);
    $line_idx--;
    (void)_664_t3;
    _664_t7 = _666_f;
    _664_t9 = &_665_y;
    _664_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _664_t8 = _664_t7(_664_t9, _664_t10);
    $line_idx--;
    (void)_664_t8;
    _664_$retval = $add_int64_t(_665_x, _665_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _664_$retval;
}

struct2 _666_f(int64_t* _666_x,uint8_t _666_fail){
    struct2 _666_$retval;
    *_666_x = 4;
    if (_666_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _666_$retval = (struct2) {.tag=1};
    *_666_x = 115;
    return _666_$retval;
BB4:
    _666_$retval = (struct2) {.tag=0};
    return _666_$retval;
}

int main(void) {
  printf("%ld",_664_main());
  return 0;
}
