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
int64_t _1716_main(void);
struct1 _1718_get(void);

/* Function definitions */
int64_t _1716_main(void){
    function0 _1716_t0;
    struct1 _1716_t1;
    struct1 _1717_x;
    int64_t _1716_$retval;
    _1716_t0 = _1718_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1716_t1 = _1716_t0();
    $line_idx--;
    _1717_x = _1716_t1;
    _1716_$retval = _1717_x._0;
    return _1716_$retval;
}

struct1 _1718_get(void){
    int64_t _1718_t1;
    struct1 _1718_$retval;
    _1718_t1 = 234;
    _1718_$retval = (struct1) {_1718_t1};
    return _1718_$retval;
}

int main(void) {
  printf("%ld",_1716_main());
  return 0;
}
