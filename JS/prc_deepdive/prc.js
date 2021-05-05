const counter = (function () {
    let num = 0;
    return {
        increse() {
            return ++num;
        },
        decrease() {
            return --num;
        }
    }
}());


console.log(counter.increse());
console.log(counter.increse());
console.log(counter.increse());
console.log(counter.decrease());
console.log(counter.decrease());
console.log(counter.decrease());
console.log(counter.decrease());
console.log(counter.decrease());