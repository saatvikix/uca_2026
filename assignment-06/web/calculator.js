
function *cal(init) {
    
    let num = init;
    console.log(`Initial value: ${num}`);

    while(true) {
        const data = yield;

        if(data.operation == 'add') {
            num += data.value;
        }
        else if(data.operation == 'subtract') {
            num -= data.value;
        }
        else if(data.operation == 'multiply') {
            num *= data.value;
        }
        else if(data.operation == 'divide') {
            if(data.value == 0) {
                console.log('Cannot divide by 0');
                continue;
            }
            num /= data.value;
        }

        console.log(num);
    }
    
}

