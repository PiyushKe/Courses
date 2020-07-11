function areThereDuplicates(...arr) {
    let freq = {};
    for (let character of arr) {
        freq[character] = (freq[character] || 0) + 1;
    }
    for (let key of Object.keys(freq)) {
        if (freq[key] > 1) {
            return true;
        }
    }
    return false;
}