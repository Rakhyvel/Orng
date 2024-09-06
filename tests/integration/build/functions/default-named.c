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
int64_t _952_main(void);
int64_t _954_add(int64_t _954_x, int64_t _954_y);


/* Function definitions */
int64_t _952_main(void){
    function0 _952_t0;
    int64_t _952_t2;
    int64_t _952_t3;
    int64_t _952_t1;
    int64_t _952_$retval;
    _952_t0 = (function0) _954_add;
    _952_t2 = 4;
    _952_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _952_t1 = _952_t0(_952_t2, _952_t3);
    $line_idx--;
    _952_$retval = _952_t1;
    return _952_$retval;
}

int64_t _954_add(int64_t _954_x, int64_t _954_y){
    int64_t _954_$retval;
    _954_$retval = $add_int64_t(_954_x, _954_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _954_$retval;
}


int main(void) {
  printf("%ld",_952_main());
  return 0;
}
