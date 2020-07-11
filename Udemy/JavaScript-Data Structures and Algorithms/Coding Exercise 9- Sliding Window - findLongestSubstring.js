function findLongestSubstring(string) {
    let window = {};
    let maxlength = 0;
    let index = 0;
    for (let character of string) {
        console.log(character);
        if (!window[character]) {
            window[character] = index;
        } else {
            // console.log(window)
            maxlength = Math.max(maxlength, Object.keys(window).length);
            for (let i of Object.keys(window)) {
                if (window[i] < window[character]) {
                    delete window[i];
                }
            }
            delete window[character];
            window[character] = index;
        }
        index++;
    }
    return Math.max(maxlength, Object.keys(window).length);
}