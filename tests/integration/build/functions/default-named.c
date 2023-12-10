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
int64_t _702_main(void);
int64_t _704_add(int64_t _704_x,int64_t _704_y);

/* Function definitions */
int64_t _702_main(void) {
    function0 _702_t0;
    int64_t _702_t2;
    int64_t _702_t3;
    int64_t _702_t1;
    int64_t _702_$retval;
    _702_t0 = _704_add;
    _702_t2 = 4;
    _702_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _702_t1 = _702_t0(_702_t2, _702_t3);
    $line_idx--;
    _702_$retval = _702_t1;
    return _702_$retval;
}

int64_t _704_add(int64_t _704_x,int64_t _704_y) {
    int64_t _704_$retval;
    _704_$retval = $add_int64_t(_704_x, _704_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _704_$retval;
}

int main(void) {
  printf("%ld",_702_main());
  return 0;
}
