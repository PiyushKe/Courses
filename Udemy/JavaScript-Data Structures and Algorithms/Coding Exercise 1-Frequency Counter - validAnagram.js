function validAnagram(a, b) {
    var freq1 = {};
    var freq2 = {};
    for (let i of a) {
        freq1[i] = (freq1[i] || 0) + 1;
    }
    for (let i of b) {
        freq2[i] = (freq2[i] || 0) + 1;
    }
    for (let i of Object.keys(freq1)) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}