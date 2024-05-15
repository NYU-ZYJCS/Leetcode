var createCounter = function(init: number) {
    let n = init;
    return {
        increment: () => ++n,
        decrement: () => --n,
        reset: () => (n = init)
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */