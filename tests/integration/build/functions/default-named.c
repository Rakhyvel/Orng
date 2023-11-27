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
int64_t _646_main(void);
int64_t _648_add(int64_t _648_x,int64_t _648_y);

/* Function definitions */
int64_t _646_main(void) {
    function0 _646_t0;
    int64_t _646_t2;
    int64_t _646_t3;
    int64_t _646_t1;
    int64_t _646_$retval;
    _646_t0 = _648_add;
    _646_t2 = 4;
    _646_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _646_t1 = _646_t0(_646_t2, _646_t3);
    $line_idx--;
    _646_$retval = _646_t1;
    return _646_$retval;
}

int64_t _648_add(int64_t _648_x,int64_t _648_y) {
    int64_t _648_$retval;
    _648_$retval = $add_int64_t(_648_x, _648_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _648_$retval;
}

int main(void) {
  printf("%ld",_646_main());
  return 0;
}
