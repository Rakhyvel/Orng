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
    int64_t _2;
    int64_t _3;
} struct0;

/* Function forward definitions */
int64_t _1_main();
struct0 _3_get_array(int64_t _3_a,int64_t _3_b);

/* Function definitions */
int64_t _1_main() {
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    $line_idx--;
    (void)_3_get_array(15, 16);
    _1_$retval = 64;
    return _1_$retval;
}

struct0 _3_get_array(int64_t _3_a,int64_t _3_b) {
    struct0 _3_$retval;
    _3_$retval = (struct0) {_3_a, _3_b, _3_a, _3_b};
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
