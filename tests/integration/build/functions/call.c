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
int64_t _956_main(void);
int64_t _958_add(int64_t _958_x,int64_t _958_y);

/* Function definitions */
int64_t _956_main(void){
    function0 _956_t0;
    int64_t _956_t2;
    int64_t _956_t3;
    int64_t _956_t1;
    int64_t _956_$retval;
    _956_t0 = _958_add;
    _956_t2 = 40;
    _956_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _956_t1 = _956_t0(_956_t2, _956_t3);
    $line_idx--;
    _956_$retval = _956_t1;
    return _956_$retval;
}

int64_t _958_add(int64_t _958_x,int64_t _958_y){
    int64_t _958_$retval;
    _958_$retval = $add_int64_t(_958_x, _958_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _958_$retval;
}

int main(void) {
  printf("%ld",_956_main());
  return 0;
}
