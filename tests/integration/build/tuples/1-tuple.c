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
int64_t _1068_main(void);
struct1 _1070_get(void);

/* Function definitions */
int64_t _1068_main(void) {
    function0 _1068_t0;
    struct1 _1068_t1;
    struct1 _1069_x;
    int64_t _1068_$retval;
    _1068_t0 = _1070_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1068_t1 = _1068_t0();
    $line_idx--;
    _1069_x = _1068_t1;
    _1068_$retval = _1069_x._0;
    return _1068_$retval;
}

struct1 _1070_get(void) {
    int64_t _1070_t1;
    struct1 _1070_$retval;
    _1070_t1 = 234;
    _1070_$retval = (struct1) {_1070_t1};
    return _1070_$retval;
}

int main(void) {
  printf("%ld",_1068_main());
  return 0;
}
