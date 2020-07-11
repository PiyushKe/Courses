function KMP_table(pattern) {
  let i = 0;
  let j = 1;
  let table = [0];
  while (j < pattern.length) {
    if (pattern[j] != pattern[i]) {
      if (i != 0) {
        i = table[i - 1];
      } else {
        table[j] = 0;
        j += 1;
      }
    } else if (pattern[j] == pattern[i]) {
      i += 1;
      table[j] = i;
      j += 1;
    }
  }
  return table;
}

function KMP_search(long, short) {
  let table = KMP_table(short);
  let count = 0;
  let i = 0;
  let j = 0;
  while (i < long.length) {
    if (long[i] == short[j]) {
      i += 1;
      j += 1;
    } else {
      if (j != 0) {
        j = table[j - 1];
      } else {
        i += 1;
      }
    }
    if (j == short.length) {
      count += 1;
      j = table[j - 1];
    }
  }
  return count;
}
console.log(KMP_search("aabaacdaabaaxaabaa", "aabaa"));
