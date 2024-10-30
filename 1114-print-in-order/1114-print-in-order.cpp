class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        pro1.set_value();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        pro1.get_future().wait();
        printSecond();
        pro2.set_value();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        pro2.get_future().wait();
        printThird();
    }
    
private:
    promise<void> pro1, pro2;
};