/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(    int64_t,     int64_t);

/* Function forward definitions */
int64_t _31_main(void);
int64_t _33_add(int64_t _33_x,int64_t _33_y);

/* Function definitions */
int64_t _31_main(void) {
    function0 _31_t0;
    int64_t _31_t2;
    int64_t _31_t3;
    int64_t _31_t1;
    int64_t _31_$retval;
    _31_t0 = _33_add;
    _31_t2 = 4;
    _31_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _31_t1 = _31_t0(_31_t2, _31_t3);
    $line_idx--;
    _31_$retval = _31_t1;
    return _31_$retval;
}

int64_t _33_add(int64_t _33_x,int64_t _33_y) {
    int64_t _33_$retval;
    _33_$retval = $add_int64_t(_33_x, _33_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _33_$retval;
}

int main(void) {
  printf("%ld",_31_main());
  return 0;
}
