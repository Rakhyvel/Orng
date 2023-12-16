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
} struct0;

/* Function forward definitions */
int64_t _202_add(int64_t _202_a,int64_t _202_b);
int64_t _192_main(void);

/* Function definitions */
int64_t _202_add(int64_t _202_a,int64_t _202_b){
    int64_t _202_$retval;
    _202_$retval = $add_int64_t(_202_a, _202_b, "tests/integration/comptime/default-init.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _202_$retval;
}

int64_t _192_main(void){
    int64_t _192_t1;
    int64_t _192_t2;
    struct0 _193_x;
    int64_t _192_$retval;
    _192_t1 = 240;
    _192_t2 = 5;
    _193_x = (struct0) {_192_t1, _192_t2};
    _192_$retval = $add_int64_t(_193_x._0, _193_x._1, "tests/integration/comptime/default-init.orng:4:10:\n    x.a + x.b\n        ^");
    return _192_$retval;
}

int main(void) {
  printf("%ld",_192_main());
  return 0;
}
