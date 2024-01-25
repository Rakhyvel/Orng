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
int64_t _986_main(void);
int64_t _988_add(int64_t _988_x, int64_t _988_y);


/* Function definitions */
int64_t _986_main(void){
    function0 _986_t0;
    int64_t _986_t2;
    int64_t _986_t3;
    int64_t _986_t1;
    int64_t _986_$retval;
    _986_t0 = _988_add;
    _986_t2 = 4;
    _986_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _986_t1 = _986_t0(_986_t2, _986_t3);
    $line_idx--;
    _986_$retval = _986_t1;
    return _986_$retval;
}

int64_t _988_add(int64_t _988_x, int64_t _988_y){
    int64_t _988_$retval;
    _988_$retval = $add_int64_t(_988_x, _988_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _988_$retval;
}


int main(void) {
  printf("%ld",_986_main());
  return 0;
}
