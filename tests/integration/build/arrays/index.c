/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct0;

/* Function forward definitions */
int64_t _2_main();
struct0 _4_get_array(int64_t _4_a,int64_t _4_b);

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t0;
    struct0 _3_x;
    int64_t _2_$retval;
    $lines[$line_idx++] = "tests/integration/arrays/index.orng:3:32:\n    let x: [4]Int  = get_array(15, 16)\n                              ^";
    _2_t0 = _4_get_array(15, 16);
    $line_idx--;
    _3_x = _2_t0;
    _2_$retval = *(int64_t*)&_3_x + *((int64_t*)&_3_x + 1) + *((int64_t*)&_3_x + 2) + *((int64_t*)&_3_x + 3);
    return _2_$retval;
}

struct0 _4_get_array(int64_t _4_a,int64_t _4_b) {
    struct0 _4_$retval;
    _4_$retval = (struct0) {_4_a, _4_b, _4_a, _4_b};
    return _4_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
