function insertion_sort(arr) {
  for (let i = 1; i < arr.length; i++) {
    let currentval = arr[i];
    for (var j = i - 1; j >= 0 && arr[j] > currentval; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = currentval;
    console.log(j);
  }
  return arr;
}

console.log(insertion_sort([10, 2, 15, 27, 39, 10, 100, -7, 500]));
