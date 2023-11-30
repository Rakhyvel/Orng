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

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _856_main(void);
int64_t _858_add(int64_t _858_x,int64_t _858_y);

/* Function definitions */
int64_t _856_main(void) {
    function0 _856_t0;
    int64_t _856_t2;
    int64_t _856_t3;
    int64_t _856_t1;
    int64_t _856_$retval;
    _856_t0 = _858_add;
    _856_t2 = 4;
    _856_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _856_t1 = _856_t0(_856_t2, _856_t3);
    $line_idx--;
    _856_$retval = _856_t1;
    return _856_$retval;
}

int64_t _858_add(int64_t _858_x,int64_t _858_y) {
    int64_t _858_$retval;
    _858_$retval = $add_int64_t(_858_x, _858_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _858_$retval;
}

int main(void) {
  printf("%ld",_856_main());
  return 0;
}
