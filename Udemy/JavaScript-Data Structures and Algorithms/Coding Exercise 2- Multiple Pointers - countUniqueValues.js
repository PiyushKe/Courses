function countUniqueValues(a) {
    let count = 0;
    for (let i = 0; i < a.length - 1; i++) {
        if (a[i] != a[i + 1]) {
            if (i === a.length - 2) {
                return (count += 2);
            }
            count += 1;     
        }
    }
    return (count);
}