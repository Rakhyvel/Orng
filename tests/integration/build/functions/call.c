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
int64_t _1048_main(void);
int64_t _1050_add(int64_t _1050_x,int64_t _1050_y);

/* Function definitions */
int64_t _1048_main(void){
    function0 _1048_t0;
    int64_t _1048_t2;
    int64_t _1048_t3;
    int64_t _1048_t1;
    int64_t _1048_$retval;
    _1048_t0 = _1050_add;
    _1048_t2 = 40;
    _1048_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _1048_t1 = _1048_t0(_1048_t2, _1048_t3);
    $line_idx--;
    _1048_$retval = _1048_t1;
    return _1048_$retval;
}

int64_t _1050_add(int64_t _1050_x,int64_t _1050_y){
    int64_t _1050_$retval;
    _1050_$retval = $add_int64_t(_1050_x, _1050_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _1050_$retval;
}

int main(void) {
  printf("%ld",_1048_main());
  return 0;
}
