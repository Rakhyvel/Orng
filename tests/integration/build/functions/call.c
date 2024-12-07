/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _944_main(void);
int64_t _946_add(int64_t _946_x, int64_t _946_y);


/* Function definitions */
int64_t _944_main(void){
    function0 _944_t0;
    int64_t _944_t2;
    int64_t _944_t3;
    int64_t _944_t1;
    int64_t _944_$retval;
    _944_t0 = (function0) _946_add;
    _944_t2 = 40;
    _944_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _944_t1 = _944_t0(_944_t2, _944_t3);
    $line_idx--;
    _944_$retval = _944_t1;
    return _944_$retval;
}

int64_t _946_add(int64_t _946_x, int64_t _946_y){
    int64_t _946_$retval;
    _946_$retval = $add_int64_t(_946_x, _946_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _946_$retval;
}


int main(void) {
  printf("%ld",_944_main());
  return 0;
}
