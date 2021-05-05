class Person {
    constructor(name) {
        this.name = name;
    }

    sayHi() {
        console.log("HI" + `${this.name}`);
    }

    static sayHello() {
        console.log("HELLO");
    }
}

const Saram = (function () {
    function Saram(name) {
        this.name = name;
    }

    Saram.prototype.sayHi = function () {
        console.log("HI" + `${this.name}`);
    }

    Saram.sayHello = function() {
        console.log("HELLO");
    }
    return Saram;
}())

const me = new Person("KIM");
me.sayHi();
me.sayHello();

const me2 = new Saram("LEE");
Saram.sayHello();
me2.sayHi();