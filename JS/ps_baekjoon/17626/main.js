const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ').map(Number);
let num = input[0];
let dp = [];
dp[0] = 0;
dp[1] = 1;
for (let i = 1; i <= num; i++){
    dp[i] = dp[1] + dp[i - 1];
    for (let j = 2; j * j <= i; j++)
        dp[i] = Math.min(dp[i], 1 + dp[i - j * j]);
    
}
console.log(dp[num]);