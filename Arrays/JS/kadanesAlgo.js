
let arr = [-1,3,4,-8,7,2];


// newer uproach
let maxSum = arr[0];
let currSum = arr[0];

for (let i = 1; i < arr.length; i++) {
    currSum = Math.max(arr[i], currSum + arr[i]);
    maxSum = Math.max(maxSum, currSum);
}

console.log(maxSum);