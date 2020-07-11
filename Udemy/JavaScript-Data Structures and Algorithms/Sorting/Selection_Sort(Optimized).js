function selection_sort(arr) {
  for (let i = 0; i < arr.length; i++) {
    let lowest = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[lowest] > arr[j]) {
        lowest = j;
      }
    }
    if (i != lowest) {
      temp = arr[lowest];
      arr[lowest] = arr[i];
      arr[i] = temp;
    }
  }
  return arr;
}
console.log(selection_sort([10, 2, 15, 27, 39, 10, 100, -7, 500]));
