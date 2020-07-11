function flatten(arr) {
    let newArray = []
    if (arr.length === 0) {
        return [];
    }
    if (arr[0] instanceof Array) {
        newArray = newArray.concat(flatten(arr[0]));
    } else if (arr[0] != []) {
        newArray.push(arr[0]);
    }
    newArray = newArray.concat(flatten(arr.slice(1)));
    return newArray;
}

console.log(flatten(([1, 2, 3, [4, 5], 6, 7, [8, [9, [10, 11]]]])));