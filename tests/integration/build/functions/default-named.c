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
int64_t _944_main(void);
int64_t _946_add(int64_t _946_x,int64_t _946_y);

/* Function definitions */
int64_t _944_main(void){
    function0 _944_t0;
    int64_t _944_t2;
    int64_t _944_t3;
    int64_t _944_t1;
    int64_t _944_$retval;
    _944_t0 = _946_add;
    _944_t2 = 4;
    _944_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _944_t1 = _944_t0(_944_t2, _944_t3);
    $line_idx--;
    _944_$retval = _944_t1;
    return _944_$retval;
}

int64_t _946_add(int64_t _946_x,int64_t _946_y){
    int64_t _946_$retval;
    _946_$retval = $add_int64_t(_946_x, _946_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _946_$retval;
}

int main(void) {
  printf("%ld",_944_main());
  return 0;
}
