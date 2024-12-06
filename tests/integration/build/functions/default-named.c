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
int64_t _958_main(void);
int64_t _960_add(int64_t _960_x, int64_t _960_y);


/* Function definitions */
int64_t _958_main(void){
    function0 _958_t0;
    int64_t _958_t2;
    int64_t _958_t3;
    int64_t _958_t1;
    int64_t _958_$retval;
    _958_t0 = (function0) _960_add;
    _958_t2 = 4;
    _958_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _958_t1 = _958_t0(_958_t2, _958_t3);
    $line_idx--;
    _958_$retval = _958_t1;
    return _958_$retval;
}

int64_t _960_add(int64_t _960_x, int64_t _960_y){
    int64_t _960_$retval;
    _960_$retval = $add_int64_t(_960_x, _960_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _960_$retval;
}


int main(void) {
  printf("%ld",_958_main());
  return 0;
}
