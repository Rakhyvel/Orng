/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _959_main(void);
int64_t _961_add(int64_t _961_x, int64_t _961_y);

/* Function definitions */
int64_t _959_main(void){
    function0 _959_t0;
    int64_t _959_t2;
    int64_t _959_t3;
    int64_t _959_t1;
    int64_t _959_$retval;
    _959_t0 = _961_add;
    _959_t2 = 4;
    _959_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _959_t1 = _959_t0(_959_t2, _959_t3);
    $line_idx--;
    _959_$retval = _959_t1;
    return _959_$retval;
}

int64_t _961_add(int64_t _961_x, int64_t _961_y){
    int64_t _961_$retval;
    _961_$retval = $add_int64_t(_961_x, _961_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _961_$retval;
}

int main(void) {
  printf("%ld",_959_main());
  return 0;
}
