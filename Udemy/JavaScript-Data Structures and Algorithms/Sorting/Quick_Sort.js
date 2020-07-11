function Quick_sort(arr, start = 0, end = arr.length - 1) {
  if (start >= end) {
    return;
  }

  function pivot(arr, start, end) {
    let pIndex = start;
    let pivot = arr[end];

    for (let i = start; i < end; i++) {
      if (arr[i] <= pivot) {
        let temp = arr[i];
        arr[i] = arr[pIndex];
        arr[pIndex] = temp;
        pIndex += 1;
      }
    }

    let temp = arr[pIndex];
    arr[pIndex] = arr[end];
    arr[end] = temp;

    return pIndex;
  }
  let pIndex = pivot(arr, start, end);
  Quick_sort(arr, start, pIndex - 1);
  Quick_sort(arr, pIndex + 1, end);
  return arr;
}

console.log(Quick_sort([1, 2, 7, 0, -7, 1], 0, 5));
