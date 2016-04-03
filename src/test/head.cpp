bool shallowEquals(int size, float a[], float b[]) {
  bool equals = true;
  for (int i = 0; i < size; i++) {
    equals = equals && a[i] == b[i];
  }
  return equals;
}
