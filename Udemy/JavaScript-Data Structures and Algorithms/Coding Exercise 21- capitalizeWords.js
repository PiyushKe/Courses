function capitalizeWords(arr) {
    let newArray = [];
    if (arr.length === 1) {
        return arr[0].toUpperCase();
    }
    newArray.push(arr[0].toUpperCase());
    return newArray.concat(capitalizeWords(arr.slice(1)));
}

console.log(capitalizeWords(['i', 'am', 'learning', 'recursion']));