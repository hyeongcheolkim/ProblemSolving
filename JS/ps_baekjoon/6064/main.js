const fs = require('fs');
//let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().split(' ').map(Number);
let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().trim().split("\n").map(e => e.split(" ").map(Number));
let t = input[0][0];
const gcd = function (a, b) {
    if (b === 0)
        return a;
    let [maxi, mini] = [Math.max(a, b), Math.min(a, b)];
    return gcd(mini, maxi % mini);
}
const lcm = function (a, b) {
    return a * b / gcd(a, b);
}
for (let i = 1; i <= t; i++) {
    let [m, n, x, y] = input[i];
    outer: for (; ;) {
        for (let i = 0; i * m + x <= lcm(m, n); i++) {
            let mod = (i * m + x) % n;
            if (mod === y || n === y && mod === 0) {
                console.log(i * m + x)
                break outer;
            }
        }
        console.log(-1);
        break outer;
    }
}