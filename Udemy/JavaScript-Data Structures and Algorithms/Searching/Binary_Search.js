function binarySearch(arr, num) {
  let start = 0,
    end = arr.length;
  function helper() {
    let mid = Math.floor((start + end) / 2);
    if (arr[mid] == num) {
      return mid;
    } else if (start >= end) {
      return -1;
    } else if (num > arr[mid]) {
      start = mid + 1;
    } else if (num < arr[mid]) {
      end = mid - 1;
    }
    return helper();
  }
  return helper();
}
console.log(binarySearch([10, 15, 25, 30, 35], 100));
