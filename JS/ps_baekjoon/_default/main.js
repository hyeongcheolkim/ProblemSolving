const fs = require('fs');
//let input = fs.readFileSync('/dev/stdin').toString().split(' ');
let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().trim().split("\n").map(e => e.split(" ").map(Number));
// let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().split(' ').map(Number);
console.log(input)