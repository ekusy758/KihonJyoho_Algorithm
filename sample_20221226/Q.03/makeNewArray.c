#include <stdio.h>
#include <stdlib.h>

int* makeNewArray(int* in) {
  int* out = NULL; // malloc(0)
  int i, tail;
  out = (int*) realloc(out, sizeof(int) * 1);
  out[0] = in[0]; // 0 = 3
  for (int i = 1; i < 6; i++) {
    tail = out[i-1]; // 0 = 3
    out = (int*) realloc(out, sizeof(int) * (i + 1));
    out[i] = tail + in[i]; // 0 = 3 + 2
  }
  return out;
}

void main() {
  int array[6] = {3, 2, 1, 6, 5, 4};
  int* result = makeNewArray(array);
  for (int i = 0; i < 6; i++) {
    printf("index[%d] : %d\n", i, result[i]);
  }
}
