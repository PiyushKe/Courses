function isSubsequence(a, b) {
    let x = {};
    let y = {};
    for (let character of a) {
        x[character] = (x[character] || 0) + 1;
    }
    for (let character of b) {
        y[character] = (y[character] || 0) + 1;
    }
    for (let key of Object.keys(x)) {
        if (y[key] >= x[key]) {
            return true;
        }
    }
    return false;
}