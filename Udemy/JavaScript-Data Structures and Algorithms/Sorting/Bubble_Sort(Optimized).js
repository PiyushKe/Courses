function bubble_sort(arr) {
  let no_swaps;
  for (let i = arr.length - 1; i > 0; i--) {
    no_swaps = true;
    for (let j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1]) {
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        no_swaps = false;
      }
    }
    if (no_swaps) {
      break;
    }
  }
  return arr;
}
console.log(bubble_sort([10, 2, 15, 27, 39, 10, 100, -7, 500]));
