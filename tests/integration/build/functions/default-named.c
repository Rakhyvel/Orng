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
int64_t _710_main(void);
int64_t _712_add(int64_t _712_x,int64_t _712_y);

/* Function definitions */
int64_t _710_main(void) {
    function0 _710_t0;
    int64_t _710_t2;
    int64_t _710_t3;
    int64_t _710_t1;
    int64_t _710_$retval;
    _710_t0 = _712_add;
    _710_t2 = 4;
    _710_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _710_t1 = _710_t0(_710_t2, _710_t3);
    $line_idx--;
    _710_$retval = _710_t1;
    return _710_$retval;
}

int64_t _712_add(int64_t _712_x,int64_t _712_y) {
    int64_t _712_$retval;
    _712_$retval = $add_int64_t(_712_x, _712_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _712_$retval;
}

int main(void) {
  printf("%ld",_710_main());
  return 0;
}
