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
int64_t _922_main(void);
int64_t _924_add(int64_t _924_x,int64_t _924_y);

/* Function definitions */
int64_t _922_main(void){
    function0 _922_t0;
    int64_t _922_t2;
    int64_t _922_t3;
    int64_t _922_t1;
    int64_t _922_$retval;
    _922_t0 = _924_add;
    _922_t2 = 40;
    _922_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _922_t1 = _922_t0(_922_t2, _922_t3);
    $line_idx--;
    _922_$retval = _922_t1;
    return _922_$retval;
}

int64_t _924_add(int64_t _924_x,int64_t _924_y){
    int64_t _924_$retval;
    _924_$retval = $add_int64_t(_924_x, _924_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _924_$retval;
}

int main(void) {
  printf("%ld",_922_main());
  return 0;
}
