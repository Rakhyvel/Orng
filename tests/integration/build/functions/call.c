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
int64_t _934_main(void);
int64_t _936_add(int64_t _936_x, int64_t _936_y);

/* Function definitions */
int64_t _934_main(void){
    function0 _934_t0;
    int64_t _934_t2;
    int64_t _934_t3;
    int64_t _934_t1;
    int64_t _934_$retval;
    _934_t0 = _936_add;
    _934_t2 = 40;
    _934_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _934_t1 = _934_t0(_934_t2, _934_t3);
    $line_idx--;
    _934_$retval = _934_t1;
    return _934_$retval;
}

int64_t _936_add(int64_t _936_x, int64_t _936_y){
    int64_t _936_$retval;
    _936_$retval = $add_int64_t(_936_x, _936_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _936_$retval;
}

int main(void) {
  printf("%ld",_934_main());
  return 0;
}
