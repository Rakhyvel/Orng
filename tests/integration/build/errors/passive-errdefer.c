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
int64_t _545_main(void);
struct2 _547_f(int64_t* _547_x,uint8_t _547_fail);

/* Function definitions */
int64_t _545_main(void){
    int64_t _546_z;
    int64_t _546_y;
    function0 _545_t2;
    int64_t* _545_t4;
    uint8_t _545_t5;
    struct2 _545_t3;
    function0 _545_t7;
    int64_t* _545_t9;
    uint8_t _545_t10;
    struct2 _545_t8;
    int64_t _545_$retval;
    _546_z = 10;
    _546_y = 10;
    _545_t2 = _547_f;
    _545_t4 = &_546_z;
    _545_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _545_t3 = _545_t2(_545_t4, _545_t5);
    $line_idx--;
    (void)_545_t3;
    _545_t7 = _547_f;
    _545_t9 = &_546_y;
    _545_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _545_t8 = _545_t7(_545_t9, _545_t10);
    $line_idx--;
    (void)_545_t8;
    _545_$retval = $add_int64_t(_546_z, _546_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _545_$retval;
}

struct2 _547_f(int64_t* _547_x,uint8_t _547_fail){
    struct2 _547_$retval;
    int64_t _547_t6;
    int64_t _547_t14;
    *_547_x = 6;
    if (_547_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _547_t6 = 100;
    *_547_x = $add_int64_t(*_547_x, _547_t6, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _547_t14 = 9;
    *_547_x = $add_int64_t(*_547_x, _547_t14, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _547_$retval;
BB9:
    _547_$retval = (struct2) {.tag=0};
    return _547_$retval;
}

int main(void) {
  printf("%ld",_545_main());
  return 0;
}
