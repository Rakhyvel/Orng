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
int64_t _680_main(void);
int64_t _682_add(int64_t _682_x,int64_t _682_y);

/* Function definitions */
int64_t _680_main(void) {
    function0 _680_t0;
    int64_t _680_t2;
    int64_t _680_t3;
    int64_t _680_t1;
    int64_t _680_$retval;
    _680_t0 = _682_add;
    _680_t2 = 40;
    _680_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _680_t1 = _680_t0(_680_t2, _680_t3);
    $line_idx--;
    _680_$retval = _680_t1;
    return _680_$retval;
}

int64_t _682_add(int64_t _682_x,int64_t _682_y) {
    int64_t _682_$retval;
    _682_$retval = $add_int64_t(_682_x, _682_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _682_$retval;
}

int main(void) {
  printf("%ld",_680_main());
  return 0;
}
