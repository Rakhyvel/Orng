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
int64_t _960_main(void);
int64_t _962_add(int64_t _962_x, int64_t _962_y);


/* Function definitions */
int64_t _960_main(void){
    function0 _960_t0;
    int64_t _960_t2;
    int64_t _960_t3;
    int64_t _960_t1;
    int64_t _960_$retval;
    _960_t0 = (function0) _962_add;
    _960_t2 = 4;
    _960_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _960_t1 = _960_t0(_960_t2, _960_t3);
    $line_idx--;
    _960_$retval = _960_t1;
    return _960_$retval;
}

int64_t _962_add(int64_t _962_x, int64_t _962_y){
    int64_t _962_$retval;
    _962_$retval = $add_int64_t(_962_x, _962_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _962_$retval;
}


int main(void) {
  printf("%ld",_960_main());
  return 0;
}
