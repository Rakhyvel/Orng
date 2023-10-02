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

/* Function definitions */
int64_t _1_main() {
    int64_t _2_x;
    int64_t _1_$retval;
    _2_x = 17;
BB1:
    if (_2_x < 36) {
        goto BB2;
    } else {
        goto BB11;
    }
BB2:
    if (_2_x % 2) {
        goto BB8;
    } else {
        goto BB4;
    }
BB11:
    _1_$retval = _2_x;
    return _1_$retval;
BB8:
    _2_x = _2_x + 1;
BB4:
    _2_x = _2_x + 9;
    goto BB1;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
