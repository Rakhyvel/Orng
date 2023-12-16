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
int64_t _896_main(void);
int64_t _898_add(int64_t _898_x,int64_t _898_y);

/* Function definitions */
int64_t _896_main(void){
    function0 _896_t0;
    int64_t _896_t2;
    int64_t _896_t3;
    int64_t _896_t1;
    int64_t _896_$retval;
    _896_t0 = _898_add;
    _896_t2 = 40;
    _896_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _896_t1 = _896_t0(_896_t2, _896_t3);
    $line_idx--;
    _896_$retval = _896_t1;
    return _896_$retval;
}

int64_t _898_add(int64_t _898_x,int64_t _898_y){
    int64_t _898_$retval;
    _898_$retval = $add_int64_t(_898_x, _898_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _898_$retval;
}

int main(void) {
  printf("%ld",_896_main());
  return 0;
}
