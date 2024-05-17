function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const n = arr.length;
    const result: number[] = new Array(n);
    
    for (let i = 0; i < n; ++i) {
        result[i] = fn(arr[i], i);
    }
    
    return result;
};