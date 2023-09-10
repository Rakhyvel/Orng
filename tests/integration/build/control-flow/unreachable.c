/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable.orng:2:30:\nfn main() -> Int {unreachable + 4}\n                            ^";
    fprintf(stderr, "panic: reached unreachable code\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
