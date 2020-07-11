function merge(arr1, arr2) {
  let i = 0;
  let j = 0;
  let temp = [];
  while (i <= arr1.length - 1 && j <= arr2.length - 1) {
    if (arr1[i] < arr2[j]) {
      temp.push(arr1[i++]);
    } else {
      temp.push(arr2[j++]);
    }
  }
  while (i <= arr1.length - 1) {
    temp.push(arr1[i++]);
  }
  while (j <= arr2.length - 1) {
    temp.push(arr2[j++]);
  }
  return temp;
}

function merge_sort(arr, start, end) {
  let mid = Math.floor((start + end) / 2);
  if (start >= end) {
    return;
  }
  merge_sort(arr, start, mid);
  merge_sort(arr, mid + 1, end);
  let temp = merge(arr.slice(start, mid + 1), arr.slice(mid + 1, end + 1));
  let j = 0;
  for (let i = start; i <= end; i++) {
    arr[i] = temp[j++];
  }
  return temp;
}

console.log(merge_sort([1, 0, 3, 8, 4, 6, 2], 0, 6));
