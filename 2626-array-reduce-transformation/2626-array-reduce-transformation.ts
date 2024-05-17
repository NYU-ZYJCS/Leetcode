type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Fn, init: number): number {
    let sum = init;
    for (const element of nums) {
        sum = fn(sum, element);
    }
    return sum;
};