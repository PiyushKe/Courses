function sameFrequency(a, b) {
    let x = {};
    let y = {};
    while (a != 0) {
        let rem = a % 10;
        x[rem] = (x[rem] || 0) + 1;
        a = Math.floor(a / 10);
    }
    while (b != 0) {
        let rem = b % 10;
        y[rem] = (y[rem] || 0) + 1;
        b = Math.floor(b / 10);
    }
    console.log(x);
    console.log(y);
    if (Object.keys(x).length != Object.keys(y).length) {
        return false;
    }
    for (let key of Object.keys(x)) {
        if (x[key] != y[key]) {
            return false;
        }
    }
    return true;
}
console.log(sameFrequency(123455, 123456));