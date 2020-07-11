function countDigits(num) {
  if (num === 0) {
    return 1;
  }
  return Math.floor(Math.log10(Math.abs(num))) + 1;
}

function maxDigits(nums) {
  let MaxDigitsCount = 1;
  for (let num of nums) {
    MaxDigitsCount = Math.max(MaxDigitsCount, countDigits(num));
  }
  return MaxDigitsCount;
}

function getDigit(num, i) {
  return Math.floor(Math.abs(num) / Math.pow(10, i)) % 10;
}

function radixSort(nums) {
  for (let i = 0; i < maxDigits(nums); i++) {
    let bucket = Array.from({ length: 10 }, () => []);
    for (let num of nums) {
      let digit = getDigit(num, i);
      bucket[digit].push(num);
    }
    nums = [].concat(...bucket);
  }
  return nums;
}

console.log(radixSort([1, 3, 2, 7, 5, 9, 10]));
