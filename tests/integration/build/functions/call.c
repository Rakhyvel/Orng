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
int64_t _885_main(void);
int64_t _887_add(int64_t _887_x,int64_t _887_y);

/* Function definitions */
int64_t _885_main(void){
    function0 _885_t0;
    int64_t _885_t2;
    int64_t _885_t3;
    int64_t _885_t1;
    int64_t _885_$retval;
    _885_t0 = _887_add;
    _885_t2 = 40;
    _885_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _885_t1 = _885_t0(_885_t2, _885_t3);
    $line_idx--;
    _885_$retval = _885_t1;
    return _885_$retval;
}

int64_t _887_add(int64_t _887_x,int64_t _887_y){
    int64_t _887_$retval;
    _887_$retval = $add_int64_t(_887_x, _887_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _887_$retval;
}

int main(void) {
  printf("%ld",_885_main());
  return 0;
}
