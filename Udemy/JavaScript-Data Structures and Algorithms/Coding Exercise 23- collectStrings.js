function collectStrings(obj) {
	let arr = [];

	function helper(obj) {
		let keys = Object.keys(obj);
		if (keys.length === 0) {
			return {};
		} else if (typeof obj[keys[0]] === 'object' && !Array.isArray(obj[keys[0]])) {
			helper(obj[keys[0]]);
		} else if (typeof obj[keys[0]] === 'string') {
			arr.push(obj[keys[0]]);
		}
		delete obj[keys[0]];
		return helper(obj);
	}
	helper(helper(obj));
	return arr;
}

const obj = {
	stuff: 'foo',
	data: {
		val: {
			thing: {
				info: 'bar',
				moreInfo: {
					evenMoreInfo: {
						weMadeIt: 'baz'
					}
				}
			}
		}
	}
};
collectStrings(obj);
// console.log(collectStrings(obj));
