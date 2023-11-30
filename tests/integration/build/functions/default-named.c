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
int64_t _879_main(void);
int64_t _881_add(int64_t _881_x,int64_t _881_y);

/* Function definitions */
int64_t _879_main(void) {
    function0 _879_t0;
    int64_t _879_t2;
    int64_t _879_t3;
    int64_t _879_t1;
    int64_t _879_$retval;
    _879_t0 = _881_add;
    _879_t2 = 4;
    _879_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _879_t1 = _879_t0(_879_t2, _879_t3);
    $line_idx--;
    _879_$retval = _879_t1;
    return _879_$retval;
}

int64_t _881_add(int64_t _881_x,int64_t _881_y) {
    int64_t _881_$retval;
    _881_$retval = $add_int64_t(_881_x, _881_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _881_$retval;
}

int main(void) {
  printf("%ld",_879_main());
  return 0;
}
