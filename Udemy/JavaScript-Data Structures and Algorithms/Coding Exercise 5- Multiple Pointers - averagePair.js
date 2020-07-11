function averagePair(arr, avg) {
    let left = 0;
    let right = arr.length - 1;
    let diff = Math.abs(avg - arr[0]);
    while (left < right) {
        if ((arr[left] + arr[right]) / 2 > avg) {
            right--;
        } else if ((arr[left] + arr[right]) / 2 < avg) {
            left++;
        } else {
            return true;
        }
    }
    return false;
}