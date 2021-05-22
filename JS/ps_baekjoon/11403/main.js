const fs = require('fs');
//let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().split(' ').map(Number);
let input = fs.readFileSync(`${__dirname}/stdin.txt`).toString().trim().split("\n").map(e => e.split(" ").map(Number));
let n = input[0];
input.shift()
graph = input.map(e => e.map(e => (e === 0 ? Infinity : e)));
for (let k = 0; k < n; k++)
    for (let i = 0; i < n; i++)
        for (let j = 0; j < n; j++)
            graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j])
graph = graph.map(e => e.map(e => (e === Infinity ? 0 : 1)));
for (i of graph)
    console.log(i.join(' '));