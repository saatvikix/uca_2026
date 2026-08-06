function *fibonacci() {
    let a = 0, b = 1, c = 0;
    while(true) {
        yield a;
        c = a + b;
        a = b;
        b = c;
    }
}