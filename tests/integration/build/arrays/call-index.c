/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

inline static void $panic(const char *restrict msg) {
    fprintf(stderr, "panic: %s\n", msg);
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

inline static void $bounds_check(const int64_t idx, const int64_t length, const char *restrict line) {
    if (0 > idx || idx >= length) {
        $lines[$line_idx++] = line;
        $panic("bounds check failed");
    }
}

inline static void $tag_check(const int64_t tag, const int64_t sel, const char *restrict line) {
    if (tag != sel) {
        $lines[$line_idx++] = line;
        $panic("inactive field");
    }
}
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
