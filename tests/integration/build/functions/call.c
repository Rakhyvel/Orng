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
int64_t _656_main(void);
int64_t _658_add(int64_t _658_x,int64_t _658_y);

/* Function definitions */
int64_t _656_main(void) {
    function0 _656_t0;
    int64_t _656_t2;
    int64_t _656_t3;
    int64_t _656_t1;
    int64_t _656_$retval;
    _656_t0 = _658_add;
    _656_t2 = 40;
    _656_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _656_t1 = _656_t0(_656_t2, _656_t3);
    $line_idx--;
    _656_$retval = _656_t1;
    return _656_$retval;
}

int64_t _658_add(int64_t _658_x,int64_t _658_y) {
    int64_t _658_$retval;
    _658_$retval = $add_int64_t(_658_x, _658_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _658_$retval;
}

int main(void) {
  printf("%ld",_656_main());
  return 0;
}
