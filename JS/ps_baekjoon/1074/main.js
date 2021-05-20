const fs = require('fs');
//let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().trim().split("\n").map(e => e.split(" ").map(Number));
let input = fs.readFileSync('/dev/stdin').toString().split(' ').map(Number);
let n = input[0];
let r = input[1];
let c = input[2];
let num = Math.pow(2, n);
let recursion = function (num, sum, r, c) {
    if (num == 1) {
        if (r >= num && c >= num)
        return sum + 4;
        else if (r >= num && c < num)
        return sum + 3;
        else if (r < num && c >= num)
        return sum + 2;
        else
        return sum + 1;
    }
    num /= 2
    if (r >= num && c >= num)
        return recursion(num, sum + 3 * Math.pow(num, 2), r - num, c - num);
    else if (r >= num && c < num)
        return recursion(num, sum + 2 * Math.pow(num, 2), r - num, c);
    else if (r < num && c >= num)
        return recursion(num, sum + 1 * Math.pow(num, 2), r, c - num);
    else
        return recursion(num, sum + 0 * Math.pow(num, 2), r, c);
}
console.log(recursion(num, 0, r, c) - 1);