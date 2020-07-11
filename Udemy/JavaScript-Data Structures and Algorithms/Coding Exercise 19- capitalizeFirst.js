function capitalizeFirst(arr) {
	let newArray = [];
	if (arr.length === 1) {
		newArray.push(arr[0][0].toUpperCase().concat(arr[0].slice(1)));
		return newArray;
	}
	newArray.push(arr[0][0].toUpperCase().concat(arr[0].slice(1)));
	newArray = newArray.concat(capitalizeFirst(arr.slice(1)));
	return newArray;
}
