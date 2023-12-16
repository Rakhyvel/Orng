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
int64_t _572_main(void);
struct2 _574_f(int64_t* _574_x,uint8_t _574_fail);

/* Function definitions */
int64_t _572_main(void){
    int64_t _573_x;
    int64_t _573_y;
    function0 _572_t2;
    int64_t* _572_t4;
    uint8_t _572_t5;
    struct2 _572_t3;
    function0 _572_t7;
    int64_t* _572_t9;
    uint8_t _572_t10;
    struct2 _572_t8;
    int64_t _572_$retval;
    _573_x = 10;
    _573_y = 10;
    _572_t2 = _574_f;
    _572_t4 = &_573_x;
    _572_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _572_t3 = _572_t2(_572_t4, _572_t5);
    $line_idx--;
    (void)_572_t3;
    _572_t7 = _574_f;
    _572_t9 = &_573_y;
    _572_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _572_t8 = _572_t7(_572_t9, _572_t10);
    $line_idx--;
    (void)_572_t8;
    _572_$retval = $add_int64_t(_573_x, _573_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _572_$retval;
}

struct2 _574_f(int64_t* _574_x,uint8_t _574_fail){
    struct2 _574_$retval;
    *_574_x = 4;
    if (_574_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _574_$retval = (struct2) {.tag=1};
    *_574_x = 115;
    return _574_$retval;
BB4:
    _574_$retval = (struct2) {.tag=0};
    return _574_$retval;
}

int main(void) {
  printf("%ld",_572_main());
  return 0;
}
