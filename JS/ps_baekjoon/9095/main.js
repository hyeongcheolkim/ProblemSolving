const fs = require('fs');
//let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().split(' ').map(Number);
let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().trim().split("\n").map(e => e.split(" ").map(Number)).flat();
n = input[0];
for (let x = 1; x <= n; x++) {
    dp = [];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (let i = 4; i <= input[x]; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    console.log(dp[input[x]]);
}

