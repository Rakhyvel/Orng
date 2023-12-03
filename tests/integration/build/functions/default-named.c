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
int64_t _678_main(void);
int64_t _680_add(int64_t _680_x,int64_t _680_y);

/* Function definitions */
int64_t _678_main(void) {
    function0 _678_t0;
    int64_t _678_t2;
    int64_t _678_t3;
    int64_t _678_t1;
    int64_t _678_$retval;
    _678_t0 = _680_add;
    _678_t2 = 4;
    _678_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _678_t1 = _678_t0(_678_t2, _678_t3);
    $line_idx--;
    _678_$retval = _678_t1;
    return _678_$retval;
}

int64_t _680_add(int64_t _680_x,int64_t _680_y) {
    int64_t _680_$retval;
    _680_$retval = $add_int64_t(_680_x, _680_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _680_$retval;
}

int main(void) {
  printf("%ld",_678_main());
  return 0;
}
