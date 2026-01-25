// this is a leetcode easy problem

let arrays = [
 [3,4,5,1,2],
[2,1,3,4],
 [1,2,3],
]


function check(arr){
    let count = 0;
    
    for (let index = 0; index < arr.length; index++) {
        if(arr[index] > arr[(index+1)%arr.length]){
            count++;
        }

    if(count > 1){
        return false;
    }     
    }

    return true;
}


for (const element of arrays) {
    console.log(check(element));
}