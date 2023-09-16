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
struct0* _4_f(struct0* _4_x);

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    struct0* _2_t6;
    struct0* _2_t5;
    int64_t _2_$retval;
    _3_x = (struct0) {1, 2, 3, 4};
    _2_t6 = &_3_x;
    $lines[$line_idx++] = "tests/integration/arrays/call-index.orng:4:7:\n    f(&mut x)^[3]\n     ^";
    _2_t5 = _4_f(_2_t6);
    $line_idx--;
    _2_$retval = *((int64_t*)_2_t5 + 3);
    return _2_$retval;
}

struct0* _4_f(struct0* _4_x) {
    struct0* _4_$retval;
    *((int64_t*)_4_x + 3) = 78;
    _4_$retval = _4_x;
    return _4_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
