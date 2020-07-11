function reverse(string) {
    if (string === '') {
        return '';
    }
    return string[string.length - 1].concat(reverse(string.slice(0, string.length - 1)));
}