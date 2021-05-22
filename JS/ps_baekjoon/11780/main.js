//baekjoon ps 11780

const fs = require('fs');
let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().trim().split("\n").map(e => e.split(" ").map(Number));
let n = input[0][0];
let m = input[1][0];
input.shift();
input.shift();
let data = Array.from(Array(n + 1), () => Array(n + 1).fill(Infinity));
let trace = Array.from(Array(n + 1), () => Array(n + 1).fill());
for (let i = 1; i <= n; i++)
    data[i][i] = 0;
for (let i = 0; i < m; i++) {
    let to = input[i][0];
    let go = input[i][1];
    let cost = input[i][2];
    data[to][go] = Math.min(cost, data[to][go]);
}
for (let k = 1; k <= n; k++)
    for (let i = 1; i <= n; i++)
        for (let j = 1; j <= n; j++)
            if (data[i][j] > data[i][k] + data[k][j]) {
                data[i][j] = data[i][k] + data[k][j];
                trace[i][j] = k;
            }
data.shift();
for (let i = 0; i < data.length; i++) {
    data[i].shift();
    for (let j = 0; j < data[i].length; j++)
        if (data[i][j] === Infinity)
            data[i][j] = 0;
}
for (i of data)
    console.log(i.join(" "));
for (let i = 1; i <= n; i++)
    for (let j = 1; j <= n; j++)
        if (data[i - 1][j - 1] >= 1) {
            let res = [];
            res[0] = 0;
            res.push(i);
            (function f(row, col) {
                let num = trace[row][col];
                if (num == undefined)
                    return;
                f(row, num);
                res.push(num);
                f(num, col);
            })(i, j);
            res.push(j);
            res[0] = res.length - 1;
            console.log(res.join(" "))
        } else
            console.log('0');
