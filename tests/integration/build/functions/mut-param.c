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
/* Function forward definitions */
int64_t _2_main();
int64_t _4_sum_down(int64_t _4_x);

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t0;
    int64_t _2_$retval;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _2_t0 = _4_sum_down(8);
    $line_idx--;
    _2_$retval = _2_t0 + 2;
    return _2_$retval;
}

int64_t _4_sum_down(int64_t _4_x) {
    int64_t _6_i;
    int64_t _4_$retval;
    _6_i = _4_x;
BB1:
    if (_6_i >= 0) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _4_x = _4_x + _6_i;
    _6_i = _6_i - 1;
    goto BB1;
BB7:
    _4_$retval = _4_x;
    return _4_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
