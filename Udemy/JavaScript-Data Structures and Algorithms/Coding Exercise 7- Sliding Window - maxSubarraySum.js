function maxSubarraySum(arr, b) {
    if (b > arr.length) {
        return null;
    }
    let maxsum = 0;
    let tempsum = 0;
    for (let i = 0; i < b; i++) {
        maxsum += arr[i];
    }
    tempsum = maxsum;
    for (let i = b; i < arr.length; i++) {
        tempsum = tempsum + arr[i] - arr[i - b];
        if (tempsum > maxsum) {
            maxsum = tempsum;
        }
    }
    return maxsum;
}
console.log(maxSubarraySum([100, 200, 300, 400], 2))