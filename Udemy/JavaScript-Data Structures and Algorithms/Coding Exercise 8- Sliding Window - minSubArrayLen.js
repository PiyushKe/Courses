function minSubArrayLen(arr, num) {
	let sum = 0;
	for (let number of arr) {
		sum += number;
	}
	if (sum < num) {
		return 0;
	}
	let left = 0;
	let right = 0;
	let currentsum = 0;
	let length = arr.length;
	while (right <= arr.length) {
		if (currentsum >= num) {
			currentsum -= arr[left];
			left++;
		}
		if (currentsum < num) {
			currentsum += arr[right];
			right++;
		}
		if (currentsum >= num && (right - left) < length) {
			if ((right - left) == 1) {
				return 1;
			}
			length = right - left;
		}
	}
	return length;
}