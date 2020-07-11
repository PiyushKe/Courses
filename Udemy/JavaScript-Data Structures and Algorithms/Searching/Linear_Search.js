function linearSearch(arr) {
    let n = 0;
    function helper(num)
    {
        if (arr[n] == num) {
        return n;
        }
        if (n == arr.length-1) {
            return -1;
        }
        n += 1;
        return(helper(num));
    }
    return helper;
}
my_func = linearSearch([10,15,25,20,30]);
console.log(my_func(5));