const fs = require('fs');
//let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().split(' ').map(Number);
let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().trim().split("\n").map(e => e.split(" ").map(Number));
console.log(input)
let t = input[0][0];
for (let i = 1; i <= t; i++) {
    let [m, n, x, y] = input[i];
    let [a, b] = [1, 1];
    while (a !== m && b !== n) {
        if (a === m)
            a = 1;
        else
            a++;
        if (b === n)
            b = 1;
        else
            b++;
        if (x === a && y === b) {
            console.log(i);
            break;
        }
    }
}