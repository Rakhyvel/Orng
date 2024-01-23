/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _987_main(void);
int64_t _989_id(int64_t _989_x);


/* Function definitions */
int64_t _987_main(void){
    function0 _987_t0;
    int64_t _987_t2;
    int64_t _987_t1;
    int64_t _987_$retval;
    _987_t0 = _989_id;
    _987_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _987_t1 = _987_t0(_987_t2);
    $line_idx--;
    _987_$retval = _987_t1;
    return _987_$retval;
}

int64_t _989_id(int64_t _989_x){
    int64_t _989_$retval;
    _989_$retval = _989_x;
    return _989_$retval;
}


int main(void) {
  printf("%ld",_987_main());
  return 0;
}
