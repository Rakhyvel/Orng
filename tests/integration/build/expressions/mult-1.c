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
int64_t _1_main();
uint8_t _6_f(int64_t _6_x);

/* Function definitions */
int64_t _1_main() {
    uint8_t _1_t1;
    int64_t _1_t0;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _1_t1 = _6_f(4);
    $line_idx--;
    if (_1_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1_t0 = 186;
    goto BB4;
BB5:
    _1_t0 = 4;
BB4:
    _1_$retval = _1_t0;
    return _1_$retval;
}

uint8_t _6_f(int64_t _6_x) {
    uint8_t _6_t0;
    uint8_t _6_$retval;
    if (_6_x == _6_x) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _6_t0 = _6_x == _6_x;
    goto BB3;
BB4:
    _6_t0 = 0;
BB3:
    _6_$retval = _6_t0;
    return _6_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
