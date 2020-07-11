function nestedEvenSum(object) {
	let sum = 0;

	function helper(object) {
		let values = Object.values(object);
		if (values[0] instanceof Object) {
			helper(values[0]);
		} else if (values[0] % 2 === 0) {
			sum += values[0];
		}
		delete object[Object.keys(object)[0]];
		if (Object.keys(object).length === 0) {
			return;
		}
		return helper(object);
	}
	helper(object);
	return sum;
}

var obj1 = {
	a: 2,
	b: {
		b: 2,
		bb: {
			b: 3,
			bb: {
				b: 2
			}
		}
	},
	c: {
		c: {
			c: 2
		},
		cc: 'ball',
		ccc: 5
	},
	d: 1,
	e: {
		e: {
			e: 2
		},
		ee: 'car'
	}
};

console.log(nestedEvenSum(obj1)); // 10
