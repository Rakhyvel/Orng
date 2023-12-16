/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _1454_main(void);
struct1 _1456_get(void);

/* Function definitions */
int64_t _1454_main(void){
    function0 _1454_t0;
    struct1 _1454_t1;
    struct1 _1455_x;
    int64_t _1454_$retval;
    _1454_t0 = _1456_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1454_t1 = _1454_t0();
    $line_idx--;
    _1455_x = _1454_t1;
    _1454_$retval = _1455_x._0;
    return _1454_$retval;
}

struct1 _1456_get(void){
    int64_t _1456_t1;
    struct1 _1456_$retval;
    _1456_t1 = 234;
    _1456_$retval = (struct1) {_1456_t1};
    return _1456_$retval;
}

int main(void) {
  printf("%ld",_1454_main());
  return 0;
}
