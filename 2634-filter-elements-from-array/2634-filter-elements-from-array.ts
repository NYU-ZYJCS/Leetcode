type Fn = (n: number, i: number) => any

function filter(arr: number[], fn: Fn): number[] {
    const n = arr.length;
    const result: number[] = [];
    
    for (let i = 0; i < n; ++i) {
        if (fn(arr[i], i)) {
            result.push(arr[i]);
        }
    }
    
    return result;
};