function majorityElement(arr) {
    let candidate = null;
    let count = 0;


    for (let num of arr) {
        if (count === 0) {
            candidate = num;
            count = 1;
        } else if (num === candidate) {
            count++;
        } else {
            count--;
        }
    }

   
    return candidate;
}


let arr = [3, 3, 4, 2, 3, 3, 5];
console.log(majorityElement(arr));
