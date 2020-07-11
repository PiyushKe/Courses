function insertion_sort(arr) {
  for (let i = 1; i < arr.length; i++) {
    for (var j = i - 1; j >= 0; j--) {
      if (arr[j] > arr[j + 1]) {
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return arr;
}

console.log(insertion_sort([10, 2, 15, 27, 39, 10, 100, -7, 500]));
